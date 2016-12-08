//
// Created on 19/11/2016.
//

#include <SFML/System/String.hpp>
#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include "Enemy.h"

Enemy::Enemy(Model *model) : Object(model) {
	ennemyspeed = 0.6f;
}

void Enemy::EnemyLoadObj(const char *ObjFile, int correction) {
	objData = new objLoader();
	objData->load((char *) ObjFile);
	this->correction = correction;
	//toString();
}

void Enemy::GenerateEnemy(int choix) {
	if (model->isMangerEnnemis() && model->camera.x >= position.fx - 0.8 && model->camera.x <= position.fx + 0.8) {
		if (model->camera.y >= position.fy - 0.8 && model->camera.y <= position.fy + 0.8) {
			Eat = true;
		}
	}
	if (!isEat()) {
		if (choix == 0) {
			GenerateEnemyAlgoAleatoire();
		}
		if (choix == 1) {
			GenerateEnemyAlgoTracker();
		}
	}

	TempsFramePrecedente = model->getTimeFrame();
}

void Enemy::GenerateEnemyAlgoAleatoire() {
// Algo sous rustine suite à une apparition étrange à l'initialisation du jeu des ennemis en dehors de la map
	int up_y = (int) (position.fy + 1);
	if (up_y < 0) {
		up_y = 0;
	} else if (up_y > (int) model->getMap().y) {
		up_y = model->getMap().y;
	}

	int up_x = (int) position.fx;
	if (up_x < 0) {
		up_x = 0;
	} else if (up_x > (int) model->getMap().x) {
		up_x = model->getMap().x;
	}


	int down_y = (int) position.fy - 1;
	if (down_y < 0) {
		down_y = 0;
	} else if (down_y > (int) model->getMap().y) {
		down_y = model->getMap().y;
	}

	int down_x = (int) position.fx;
	if (down_x < 0) {
		down_x = 0;
	} else if (down_x > (int) model->getMap().x) {
		down_x = model->getMap().x;
	}


	int left_y = (int) position.fy;
	if (left_y < 0) {
		left_y = 0;
	} else if (left_y > (int) model->getMap().y) {
		left_y = model->getMap().y;
	}

	int left_x = (int) position.fx - 1;
	if (left_x < 0) {
		left_x = 0;
	} else if (left_x > (int) model->getMap().x) {
		left_x = model->getMap().x;
	}


	int right_y = (int) position.fy;
	if (right_y < 0) {
		right_y = 0;
	} else if (right_y > (int) model->getMap().y) {
		right_y = model->getMap().y;
	}

	int right_x = (int) position.fx + 1;
	if (right_x < 0) {
		right_x = 0;
	} else if (right_x > (int) model->getMap().x) {
		right_x = model->getMap().x;
	}


	int diagupleft_y = (int) position.fy + 1;
	if (diagupleft_y < 0) {
		diagupleft_y = 0;
	} else if (diagupleft_y > (int) model->getMap().y) {
		diagupleft_y = model->getMap().y;
	}

	int diagupleft_x = (int) position.fx - 1;
	if (diagupleft_x < 0) {
		diagupleft_x = 0;
	} else if (diagupleft_x > (int) model->getMap().x) {
		diagupleft_x = model->getMap().x;
	}


	int diagupright_y = (int) position.fy + 1;
	if (diagupright_y < 0) {
		diagupright_y = 0;
	} else if (diagupright_y > (int) model->getMap().y) {
		diagupright_y = model->getMap().y;
	}

	int diagupright_x = (int) position.fx + 1;
	if (diagupright_x < 0) {
		diagupright_x = 0;
	} else if (diagupright_x > (int) model->getMap().x) {
		diagupright_x = model->getMap().x;
	}


	int diagdownleft_y = (int) position.fy - 1;
	if (diagdownleft_y < 0) {
		diagdownleft_y = 0;
	} else if (diagdownleft_y > (int) model->getMap().y) {
		diagdownleft_y = model->getMap().y;
	}

	int diagdownleft_x = (int) position.fx - 1;
	if (diagdownleft_x < 0) {
		diagdownleft_x = 0;
	} else if (diagdownleft_x > (int) model->getMap().x) {
		diagdownleft_x = model->getMap().x;
	}

	int diagdownright_y = (int) position.fy - 1;
	if (diagdownright_y < 0) {
		diagdownright_y = 0;
	} else if (diagdownright_y > (int) model->getMap().y) {
		diagdownright_y = model->getMap().y;
	}

	int diagdownright_x = (int) position.fx + 1;
	if (diagdownright_x < 0) {
		diagdownright_x = 0;
	} else if (diagdownright_x > (int) model->getMap().x) {
		diagdownright_x = model->getMap().x;
	}

	if (!model->GetFreeze()) {

		if ((model->getMatrice()[up_x][up_y] == 1) || (model->getMatrice()[down_x][down_y] == 1) ||
			(model->getMatrice()[left_x][left_y] == 1)
			|| (model->getMatrice()[right_x][right_y] == 1) ||
			(model->getMatrice()[diagdownleft_x][diagdownleft_y] == 1)
			|| (model->getMatrice()[diagdownright_x][diagdownright_y] == 1) ||
			(model->getMatrice()[diagupleft_x][diagupleft_y] == 1)
			|| (model->getMatrice()[diagupright_x][diagupright_y] == 1)) {
			position.fx = memposx;
			position.fy = memposy;
			alea = rand() % 4;
		} else {
			memposx = position.fx;
			memposy = position.fy;
			if (ennemyspeed * model->getDeltaTimeFrame(TempsFramePrecedente) / 100 <=
				1) {    // Évite un déplacement extrême des ennemis en cas de delta temps excessif (démarrage du jeu ou ralentissement anormal), Par ailleurs la vérification des collisions ne contrôle que + ou -1
				if (alea == 0) { position.fy -= ennemyspeed * model->getDeltaTimeFrame(TempsFramePrecedente) / 100; }
				if (alea == 1) { position.fy += ennemyspeed * model->getDeltaTimeFrame(TempsFramePrecedente) / 100; }
				if (alea == 2) { position.fx -= ennemyspeed * model->getDeltaTimeFrame(TempsFramePrecedente) / 100; }
				if (alea == 3) { position.fx += ennemyspeed * model->getDeltaTimeFrame(TempsFramePrecedente) / 100; }
			}

		}
	}

	if (objData != NULL) {
		GenerateEnemyObj();
	} else {
		CreateCube(1, 1, 4, position.fx, position.fy, 0);
	}
}

void Enemy::CorrectifObj() {
	/*glPushMatrix();*/
	switch (correction) {
		case 1:        // Silent
			glScalef(0.015, 0.015, 0.015);
			glTranslated(position.fx + (position.fx / (42.0 / 2800.0)), position.fy + (position.fy / (42.0 / 2800.0)),
						 2);
			glRotated(90, 1, 0, 0);
			break;
		case 2:        // Billy
			glScalef(1.2, 1.2, 1.2);
			glTranslated(position.fx - (position.fx / (42.0 / 6.6)), position.fy - (position.fy / (42.0 / 6.7)), 0);
			glRotated(90, 1, 0, 0);
			break;
		case 3:        // Dalek
			glScalef(0.015, 0.015, 0.015);
			glTranslated(position.fx + (position.fx / (42.0 / 2790.0)), position.fy + (position.fy / (42.0 / 2790.0)),
						 1.5);
			glRotated(90, 1, 0, 0);
			break;
		case 4:        // PortalTurretV2
			glScalef(0.045, 0.045, 0.045);
			glTranslated(position.fx + (position.fx / (42.0 / 902.0)), position.fy + (position.fy / (42.0 / 900.0)),
						 35);
			glRotated(90, 1, 0, 0);
			break;

		default:
			break;
	}
}

void Enemy::GenerateEnemyAlgoTracker() {
// Non fonctionnel (En revanche, fonctionnel dans les premières versions du jeu ...!)
	int up_y = (int) position.fy + 1;
	int up_x = (int) position.fx;

	int down_y = (int) position.fy - 1;
	int down_x = (int) position.fx;

	int left_y = (int) position.fy;
	int left_x = (int) position.fx - 1;

	int right_y = (int) position.fy;
	int right_x = (int) position.fx + 1;

	int diagupleft_y = (int) position.fy + 1;
	int diagupleft_x = (int) position.fx - 1;

	/*int diagupright_y = (int) position.fy + 1;
	int diagupright_x = (int) position.fx + 1;*/        // Manque la condition !!

	int diagdownleft_y = (int) position.fy - 1;
	int diagdownleft_x = (int) position.fx - 1;

	int diagdownright_y = (int) position.fy - 1;
	int diagdownright_x = (int) position.fx + 1;

	if (!model->GetFreeze()) {

		if (model->getMatrice()[up_x][up_y] == 1) {
			position.fy -= ennemyspeed *
						   model->getDeltaTimeFrame(TempsFramePrecedente) / 100;
		}
		if (model->getMatrice()[down_x][down_y] == 1) {
			position.fy += ennemyspeed *
						   model->getDeltaTimeFrame(TempsFramePrecedente) /
						   100;
		}
		if ((model->getMatrice()[left_x][left_y] == 1)) {
			position.fx += ennemyspeed * model->getDeltaTimeFrame(
					TempsFramePrecedente) / 100;
		}
		if (model->getMatrice()[right_x][right_y] == 1) {
			position.fx -= ennemyspeed * model->getDeltaTimeFrame(
					TempsFramePrecedente) / 100;
		}
		if (model->getMatrice()[diagdownleft_x][diagdownleft_y] == 1) {
			position.fx += ennemyspeed *
						   model->getDeltaTimeFrame(
								   TempsFramePrecedente) /
						   100;
			position.fy += ennemyspeed * model->getDeltaTimeFrame(TempsFramePrecedente) / 100;
		}
		if (model->getMatrice()[diagdownright_x][diagdownright_y] == 1) {
			position.fx -= ennemyspeed *
						   model->getDeltaTimeFrame(
								   TempsFramePrecedente) /
						   100;
			position.fy += ennemyspeed * model->getDeltaTimeFrame(TempsFramePrecedente) / 100;
		}
		if (model->getMatrice()[diagupleft_x][diagupleft_y] == 1) {
			position.fx += ennemyspeed *
						   model->getDeltaTimeFrame(
								   TempsFramePrecedente) / 100;
			position.fy -= ennemyspeed * model->getDeltaTimeFrame(TempsFramePrecedente) / 100;
		}
		if (model->getMatrice()[diagdownleft_x][diagdownleft_y] == 1) {
			position.fx -= ennemyspeed *
						   model->getDeltaTimeFrame(
								   TempsFramePrecedente) /
						   100;
			position.fy -= ennemyspeed * model->getDeltaTimeFrame(TempsFramePrecedente) / 100;
		}
		if ((model->getMatrice()[up_x][up_y] != 1) && (model->getMatrice()[left_x][left_y] != 1) &&
			(model->getMatrice()[right_x][right_y] != 1) && (model->getMatrice()[down_x][down_y] != 1)) {

			if (position.fx < model->camera.x) {
				position.fx +=
						ennemyspeed * model->getDeltaTimeFrame(TempsFramePrecedente) /
						100;
			}
			if (position.fx > model->camera.x) {
				position.fx -=
						ennemyspeed * model->getDeltaTimeFrame(TempsFramePrecedente) /
						100;
			}
			if (position.fy < model->camera.y) {
				position.fy +=
						ennemyspeed * model->getDeltaTimeFrame(TempsFramePrecedente) /
						100;
			}
			if (position.fy > model->camera.y) {
				position.fy -=
						ennemyspeed * model->getDeltaTimeFrame(TempsFramePrecedente) /
						100;
			}

		}
	}
	CreateCube(1, 1, 4, position.fx, position.fy, 0);
	//GenerateEnemyObj();
}

// -- TEMPO
void Enemy::CreateCube(float longueur, float largeur, float hauteur, float x, float y, float z) {

	glBegin(GL_QUADS);
	if (model->isMangerEnnemis()) {
		glColor3ub(150, 150, 255);
	} else {
		glColor3ub(255, 0, 0); //face rouge
	}
	glTexCoord2i(1, 0);
	glVertex3d(x + longueur, y + largeur, z + hauteur);
	glTexCoord2i(1, 0);
	glVertex3d(x + longueur, y + largeur, z + 0);
	glTexCoord2i(1, 0);
	glVertex3d(x + 0, y + largeur, z + 0);
	glTexCoord2i(1, 0);
	glVertex3d(x + 0, y + largeur, z + hauteur);

	if (model->isMangerEnnemis()) {
		glColor3ub(150, 150, 255);
	} else {
		glColor3ub(0, 255, 0); //face verte
	}
	glTexCoord2i(1, 0);
	glVertex3d(x + longueur, y + 0, z + hauteur);
	glTexCoord2i(1, 0);
	glVertex3d(x + longueur, y + 0, z + 0);
	glTexCoord2i(1, 0);
	glVertex3d(x + longueur, y + largeur, z + 0);
	glTexCoord2i(1, 0);
	glVertex3d(x + longueur, y + largeur, z + hauteur);

	if (model->isMangerEnnemis()) {
		glColor3ub(150, 150, 255);
	} else {
		glColor3ub(0, 0, 255); //face bleue
	}
	glTexCoord2i(1, 0);
	glVertex3d(x + 0, y + 0, z + hauteur);
	glTexCoord2i(1, 0);
	glVertex3d(x + 0, y + 0, z + 0);
	glTexCoord2i(1, 0);
	glVertex3d(x + longueur, y + 0, z + 0);
	glTexCoord2i(1, 0);
	glVertex3d(x + longueur, y + 0, z + hauteur);

	if (model->isMangerEnnemis()) {
		glColor3ub(150, 150, 255);
	} else {
		glColor3ub(255, 255, 0); //face jaune
	}
	glTexCoord2i(1, 0);
	glVertex3d(x + 0, y + largeur, z + hauteur);
	glTexCoord2i(1, 0);
	glVertex3d(x + 0, y + largeur, z + 0);
	glTexCoord2i(1, 0);
	glVertex3d(x + 0, y + 0, z + 0);
	glTexCoord2i(1, 0);
	glVertex3d(x + 0, y + 0, z + hauteur);

	if (model->isMangerEnnemis()) {
		glColor3ub(150, 150, 255);
	} else {
		glColor3ub(0, 255, 255); //face cyan
	}
	glTexCoord2i(1, 0);
	glVertex3d(x + longueur, y + largeur, z + 0);
	glTexCoord2i(1, 0);
	glVertex3d(x + longueur, y + 0, z + 0);
	glTexCoord2i(1, 0);
	glVertex3d(x + 0, y + 0, z + 0);
	glTexCoord2i(1, 0);
	glVertex3d(x + 0, y + largeur, z + 0);

	if (model->isMangerEnnemis()) {
		glColor3ub(150, 150, 255);
	} else {
		glColor3ub(255, 0, 255); //face magenta
	}
	glTexCoord2i(1, 0);
	glVertex3d(x + longueur, y + 0, z + hauteur);
	glTexCoord2i(1, 0);
	glVertex3d(x + longueur, y + largeur, z + hauteur);
	glTexCoord2i(1, 0);
	glVertex3d(x + 0, y + largeur, z + hauteur);
	glTexCoord2i(1, 0);
	glVertex3d(x + 0, y + 0, z + hauteur);

	glEnd();
}
// -- TEMPO

void Enemy::GenerateEnemyObj() {
	CorrectifObj();
	if (alea == 1) { glRotatef(180, 0, 1, 0); }
	if (alea == 2) { glRotatef(-90, 0, 1, 0); }
	if (alea == 3) { glRotatef(90, 0, 1, 0); }

	glBegin(GL_TRIANGLES);
	if (model->isMangerEnnemis()) {
		glColor3ub(150, 150, 255);
	} else {
		glColor3ub(164, 11, 8);
	}
	//glTexCoord2i(position.fx, position.fy);


	for (int i = 0; i < objData->textureCount; i++) {
		obj_face *o = objData->faceList[i];
		for (int j = 0; j < 3; j++) {
			GenerateTexture(objData->textureList[o->vertex_index[j]]);
		}
	}




	/*Faces*/
	for (int i = 0; i < objData->faceCount; i++) {
		obj_face *o = objData->faceList[i];
		for (int j = 0; j < 3; j++) {
			GenerateVector(objData->vertexList[o->vertex_index[j]]);
		}
	}

	/*Spheres*/
	for (int i = 0; i < objData->sphereCount; i++) {
		obj_sphere *o = objData->sphereList[i];
		GenerateVector(objData->vertexList[o->pos_index]);
		GenerateNormal(objData->normalList[o->up_normal_index]);
		GenerateNormal(objData->normalList[o->equator_normal_index]);
	}

	/*Planes*/
	for (int i = 0; i < objData->planeCount; i++) {
		obj_plane *o = objData->planeList[i];
		GenerateVector(objData->vertexList[o->pos_index]);
		GenerateNormal(objData->normalList[o->normal_index]);
		GenerateNormal(objData->normalList[o->rotation_normal_index]);
	}

	/*Point lights*/
	for (int i = 0; i < objData->lightPointCount; i++) {
		obj_light_point *o = objData->lightPointList[i];
		GenerateVector(objData->vertexList[o->pos_index]);
	}

	/*Disc lights*/
	for (int i = 0; i < objData->lightDiscCount; i++) {
		obj_light_disc *o = objData->lightDiscList[i];
		GenerateVector(objData->vertexList[o->pos_index]);
		GenerateNormal(objData->normalList[o->normal_index]);
	}

	/*Quad lights*/
	for (int i = 0; i < objData->lightQuadCount; i++) {
		obj_light_quad *o = objData->lightQuadList[i];
		GenerateVector(objData->vertexList[o->vertex_index[0]]);
		GenerateVector(objData->vertexList[o->vertex_index[1]]);
		GenerateVector(objData->vertexList[o->vertex_index[2]]);
		GenerateVector(objData->vertexList[o->vertex_index[3]]);
	}

	if (objData->camera != NULL) {
		GenerateVector(objData->vertexList[objData->camera->camera_pos_index]);
		GenerateVector(objData->vertexList[objData->camera->camera_look_point_index]);
		GenerateNormal(objData->normalList[objData->camera->camera_up_norm_index]);
	}

	glEnd();
	/*glPopMatrix();*/
	if (alea == 1) { glRotatef(-180, 0, 1, 0); }
	if (alea == 2) { glRotatef(90, 0, 1, 0); }
	if (alea == 3) { glRotatef(-90, 0, 1, 0); }
}

void Enemy::GenerateVector(obj_vector *v) {
	glVertex3d(v->e[0], v->e[1], v->e[2]);
}

void Enemy::GenerateNormal(obj_vector *n) {
	glNormal3d(n->e[0], n->e[1], n->e[2]);
}

void Enemy::GenerateTexture(obj_vector *t) {
	glTexCoord3d(t->e[0], t->e[1], t->e[2]);
}

void Enemy::toString() {
	printf("Number of vertices: %i\n", objData->vertexCount);
	printf("Number of vertex normals: %i\n", objData->normalCount);
	printf("Number of texture coordinates: %i\n", objData->textureCount);
	printf("\n");

	//--------------
	printf("Number of texture: %i\n", objData->textureCount);
	for (int i = 0; i < objData->textureCount; i++) {
		obj_face *o = objData->faceList[i];
		printf(" texture ");
		for (int j = 0; j < 3; j++) {
			printVector(objData->textureList[o->vertex_index[j]]);
		}
	}
	//--------------

	printf("Number of faces: %i\n", objData->faceCount);
	for (int i = 0; i < objData->faceCount; i++) {
		obj_face *o = objData->faceList[i];
		printf(" face ");
		for (int j = 0; j < 3; j++) {
			printVector(objData->vertexList[o->vertex_index[j]]);
		}
		printf("\n");
	}

	printf("\n");

	printf("Number of spheres: %i\n", objData->sphereCount);
	for (int i = 0; i < objData->sphereCount; i++) {
		obj_sphere *o = objData->sphereList[i];
		printf(" sphere ");
		printVector(objData->vertexList[o->pos_index]);
		printVector(objData->normalList[o->up_normal_index]);
		printVector(objData->normalList[o->equator_normal_index]);
		printf("\n");
	}

	printf("\n");

	printf("Number of planes: %i\n", objData->planeCount);
	for (int i = 0; i < objData->planeCount; i++) {
		obj_plane *o = objData->planeList[i];
		printf(" plane ");
		printVector(objData->vertexList[o->pos_index]);
		printVector(objData->normalList[o->normal_index]);
		printVector(objData->normalList[o->rotation_normal_index]);
		printf("\n");
	}

	printf("\n");

	printf("Number of point lights: %i\n", objData->lightPointCount);
	for (int i = 0; i < objData->lightPointCount; i++) {
		obj_light_point *o = objData->lightPointList[i];
		printf(" plight ");
		printVector(objData->vertexList[o->pos_index]);
		printf("\n");
	}

	printf("\n");

	printf("Number of disc lights: %i\n", objData->lightDiscCount);
	for (int i = 0; i < objData->lightDiscCount; i++) {
		obj_light_disc *o = objData->lightDiscList[i];
		printf(" dlight ");
		printVector(objData->vertexList[o->pos_index]);
		printVector(objData->normalList[o->normal_index]);
		printf("\n");
	}

	printf("\n");

	printf("Number of quad lights: %i\n", objData->lightQuadCount);
	for (int i = 0; i < objData->lightQuadCount; i++) {
		obj_light_quad *o = objData->lightQuadList[i];
		printf(" qlight ");
		printVector(objData->vertexList[o->vertex_index[0]]);
		printVector(objData->vertexList[o->vertex_index[1]]);
		printVector(objData->vertexList[o->vertex_index[2]]);
		printVector(objData->vertexList[o->vertex_index[3]]);
		printf("\n");
	}

	printf("\n");

	if (objData->camera != NULL) {
		printf("Found a camera\n");
		printf(" position: ");
		printVector(objData->vertexList[objData->camera->camera_pos_index]);
		printf("\n looking at: ");
		printVector(objData->vertexList[objData->camera->camera_look_point_index]);
		printf("\n up normal: ");
		printVector(objData->normalList[objData->camera->camera_up_norm_index]);
		printf("\n");
	}

	printf("\n");

	printf("Number of materials: %i\n", objData->materialCount);
	for (int i = 0; i < objData->materialCount; i++) {
		obj_material *mtl = objData->materialList[i];
		printf(" name: %s", mtl->name);
		printf(" amb: %.2f ", mtl->amb[0]);
		printf("%.2f ", mtl->amb[1]);
		printf("%.2f\n", mtl->amb[2]);

		printf(" diff: %.2f ", mtl->diff[0]);
		printf("%.2f ", mtl->diff[1]);
		printf("%.2f\n", mtl->diff[2]);

		printf(" spec: %.2f ", mtl->spec[0]);
		printf("%.2f ", mtl->spec[1]);
		printf("%.2f\n", mtl->spec[2]);

		printf(" reflect: %.2f\n", mtl->reflect);
		printf(" trans: %.2f\n", mtl->trans);
		printf(" glossy: %lf\n", mtl->glossy);
		printf(" shiny: %lf\n", mtl->shiny);
		printf(" refact: %.2f\n", mtl->refract_index);

		printf(" texture: %s\n", mtl->texture_filename);
		printf("\n");
	}

	printf("\n");

	//vertex, normal, and texture test
	/*if (objData->textureCount > 2 && objData->normalCount > 2 && objData->faceCount > 2) {*/
	printf("Detailed face data:\n");

	for (int i = 0; i < 3; i++) {
		obj_face *o = objData->faceList[i];
		printf(" face ");
		for (int j = 0; j < 3; j++) {
			printf("%i/", o->vertex_index[j]);
			printf("%i/", o->texture_index[j]);
			printf("%i ", o->normal_index[j]);
		}
		printf("\n");
	}
	/*}*/

}

bool Enemy::isEat() {
	return Eat;
}

void Enemy::printVector(obj_vector *v) {
	printf("%.2f,", v->e[0]);
	printf("%.2f,", v->e[1]);
	printf("%.2f  ", v->e[2]);
}

Enemy::~Enemy() {
	std::cout << "Destructeur de enemy" << std::endl;
	if (objData != NULL) delete (objData);
}
