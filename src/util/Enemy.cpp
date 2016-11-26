//
// Created by Valentin on 19/11/2016.
//

#include <SFML/System/String.hpp>
#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include "Enemy.h"

Enemy::Enemy(Model *model) : Object(model) {
	ennemyspeed = 0.3f;
};

void Enemy::EnemyLoadObj(const char *ObjFile) {
	objData = new objLoader();
	objData->load((char *) ObjFile);
	toString();
}

void Enemy::GenerateEnemy() {
	if (objData == NULL) {
		GenerateEnemyCube();
	} else {
		GenerateEnemyObj();
	}
	TempsFramePrecedente = model->getTimeFrame();
}

void Enemy::GenerateEnemyCube() {

	int up_y = (int) position.fy + 1;
	int up_x = (int) position.fx;

	int down_y = (int) position.fy - 1;
	int down_x = (int) position.fx;

	int left_y = (int) position.fy;
	int left_x = (int) position.fx - 1;

	int right_y = (int) position.fy;
	int right_x = (int) position.fx + 1;


    if(!model->GetFreeze()) {
        if (model->getMatrice()[up_x][up_y] == 1) { position.fy -= ennemyspeed * model->getDeltaTimeFrame(TempsFramePrecedente) / 100; }
        if (model->getMatrice()[down_x][down_y] == 1) { position.fy += ennemyspeed * model->getDeltaTimeFrame(TempsFramePrecedente) / 100; }
        if ((model->getMatrice()[left_x][left_y] == 1)) { position.fx += ennemyspeed * model->getDeltaTimeFrame(TempsFramePrecedente) / 100; }
        if (model->getMatrice()[right_x][right_y] == 1) { position.fx -= ennemyspeed * model->getDeltaTimeFrame(TempsFramePrecedente) / 100; }
        if ((model->getMatrice()[up_x][up_y] != 1) && (model->getMatrice()[left_x][left_y] != 1) &&
            (model->getMatrice()[right_x][right_y] != 1) && (model->getMatrice()[down_x][down_y] != 1)) {

            if (position.fx < model->camera.x) { position.fx += ennemyspeed * model->getDeltaTimeFrame(TempsFramePrecedente) / 100; }
            if (position.fx > model->camera.x) { position.fx -= ennemyspeed * model->getDeltaTimeFrame(TempsFramePrecedente) / 100; }
            if (position.fy < model->camera.y) { position.fy += ennemyspeed * model->getDeltaTimeFrame(TempsFramePrecedente) / 100; }
            if (position.fy > model->camera.y) { position.fy -= ennemyspeed * model->getDeltaTimeFrame(TempsFramePrecedente) / 100; }

        }
    }
	CreateCube(1, 1, 4, position.fx, position.fy, 0);


}

// -- TEMPO
void Enemy::CreateCube(float longueur, float largeur, float hauteur, float x, float y, float z) {

	glBegin(GL_QUADS);
	glColor3ub(255, 0, 0); //face rouge
	glTexCoord2i(1, 0);
	glVertex3d(x + longueur, y + largeur, z + hauteur);
	glTexCoord2i(1, 0);
	glVertex3d(x + longueur, y + largeur, z + 0);
	glTexCoord2i(1, 0);
	glVertex3d(x + 0, y + largeur, z + 0);
	glTexCoord2i(1, 0);
	glVertex3d(x + 0, y + largeur, z + hauteur);

	glColor3ub(0, 255, 0); //face verte
	glTexCoord2i(1, 0);
	glVertex3d(x + longueur, y + 0, z + hauteur);
	glTexCoord2i(1, 0);
	glVertex3d(x + longueur, y + 0, z + 0);
	glTexCoord2i(1, 0);
	glVertex3d(x + longueur, y + largeur, z + 0);
	glTexCoord2i(1, 0);
	glVertex3d(x + longueur, y + largeur, z + hauteur);

	glColor3ub(0, 0, 255); //face bleue
	glTexCoord2i(1, 0);
	glVertex3d(x + 0, y + 0, z + hauteur);
	glTexCoord2i(1, 0);
	glVertex3d(x + 0, y + 0, z + 0);
	glTexCoord2i(1, 0);
	glVertex3d(x + longueur, y + 0, z + 0);
	glTexCoord2i(1, 0);
	glVertex3d(x + longueur, y + 0, z + hauteur);

	glColor3ub(255, 255, 0); //face jaune
	glTexCoord2i(1, 0);
	glVertex3d(x + 0, y + largeur, z + hauteur);
	glTexCoord2i(1, 0);
	glVertex3d(x + 0, y + largeur, z + 0);
	glTexCoord2i(1, 0);
	glVertex3d(x + 0, y + 0, z + 0);
	glTexCoord2i(1, 0);
	glVertex3d(x + 0, y + 0, z + hauteur);

	glColor3ub(0, 255, 255); //face cyan
	glTexCoord2i(1, 0);
	glVertex3d(x + longueur, y + largeur, z + 0);
	glTexCoord2i(1, 0);
	glVertex3d(x + longueur, y + 0, z + 0);
	glTexCoord2i(1, 0);
	glVertex3d(x + 0, y + 0, z + 0);
	glTexCoord2i(1, 0);
	glVertex3d(x + 0, y + largeur, z + 0);

	glColor3ub(255, 0, 255); //face magenta
	glTexCoord2i(1, 0);
	glVertex3d(x + longueur, y + 0, z + hauteur);
	glTexCoord2i(1, 0);
	glVertex3d(x + longueur, y + largeur, z + hauteur);
	glTexCoord2i(1, 0);
	glVertex3d(x + 0, y + largeur, z + hauteur);
	glTexCoord2i(1, 0);
	glVertex3d(x + 0, y + 0, z + hauteur);

	glColor3ub(255, 255, 0); //face jaune
	glTexCoord2i(1, 0);
	glVertex3d(x + 0, y + largeur, z + hauteur);
	glTexCoord2i(1, 0);
	glVertex3d(x + 0, y + largeur, z + 0);
	glTexCoord2i(1, 0);
	glVertex3d(x + 0, y + 0, z + 0);
	glTexCoord2i(1, 0);
	glVertex3d(x + 0, y + 0, z + hauteur);

	glEnd();
}
// -- TEMPO

void Enemy::GenerateEnemyObj() {
	glBegin(GL_TRIANGLES);
	glTexCoord2i(position.ix, position.iy);


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

void Enemy::printVector(obj_vector *v) {
	printf("%.2f,", v->e[0]);
	printf("%.2f,", v->e[1]);
	printf("%.2f  ", v->e[2]);
}

Enemy::~Enemy() {
	std::cout << "Destructeur de enemy" << std::endl;
	if (objData != NULL) delete (objData);
}
