#include <GL/gl.h>
#include <iostream>
#include <SFML/Graphics/Texture.hpp>
#include <GL/glu.h>
#include "Gameobject.h"
#include <ctime>
#include <afxres.h>


Gameobject::Gameobject(Model *model) {
	this->model = model;
}

void Gameobject::CreateCoin(int x, int y) {

    glColor3ub(157, 0, 157);
    GLUquadricObj *quadra = gluNewQuadric();
    glPushMatrix();
    glTranslatef(x, y, model->piece_height);
    gluSphere(quadra, 0.3, 10, 10);
    glPopMatrix();
    gluDeleteQuadric(quadra);
}

void Gameobject::CreateSpeedCoin(int x, int y) {

    glColor3ub(0, 0, 0);
    GLUquadricObj *quadra = gluNewQuadric();
    glPushMatrix();
    glTranslatef(x, y, model->piece_height);
    gluSphere(quadra, 0.5, 10, 10);
    glPopMatrix();
    gluDeleteQuadric(quadra);
}


void Gameobject::CreateCube(float longueur, float largeur, float hauteur, float x, float y, float z) {

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

void Gameobject::CreateSkyBox(float longueur, float largeur, float hauteur, float x, float y, float z) {

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

/*    glColor3ub(0, 255, 255); //face cyan
    glTexCoord2i(1, 0);
    glVertex3d(x + longueur, y + largeur, z + 0);
    glTexCoord2i(1, 0);
    glVertex3d(x + longueur, y + 0, z + 0);
    glTexCoord2i(1, 0);
    glVertex3d(x + 0, y + 0, z + 0);
    glTexCoord2i(1, 0);
    glVertex3d(x + 0, y + largeur, z + 0);*/

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

void Gameobject::CreateSol() {
	glBegin(GL_QUADS);
	glColor3ub(0, 5, 60); //sol
	glTexCoord2i(0, 1);
	glVertex2d(model->map.x, model->map.y);
	glTexCoord2i(1, 0);
	glVertex2d(model->map.x, 0);
	glTexCoord2i(1, 1);
	glVertex2d(0, 0);
	glTexCoord2i(0, 0);
	glVertex2d(0, model->map.y);
	glEnd();
}

void Gameobject::GenerateMap() {
	for (unsigned int x = 0; x < model->getMap().x; x++) {
		for (unsigned int y = 0; y < model->getMap().y; y++) {
			if (model->getMatrice()[x][y] == 1) {
				CreateCube(1, 1, 4, x, y, 0);}
			else if (model->getMatrice()[x][y] == 2) {
				CreateCoin(x, y);
			}
            else if (model->getMatrice()[x][y] == 3){
                CreateSpeedCoin(x,y);
            }

		}
	}
}

void Gameobject::Ghost1() {

    up_y = (int)y1 + 1;
    up_x =(int) x1;

    down_y =(int) y1 - 1;
    down_x =(int) x1;

    left_y =(int) y1;
    left_x =(int) x1 - 1;

    right_y =(int) y1;
    right_x =(int) x1 + 1;


    if (model->getMatrice()[up_x][up_y] == 1) { y1-= ennemyspeed; }
    if (model->getMatrice()[down_x][down_y] == 1) { y1 += ennemyspeed; }
    if ((model->getMatrice()[left_x][left_y] == 1)) {x1 += ennemyspeed;}
    if (model->getMatrice()[right_x][right_y] == 1) { x1 -= ennemyspeed;}
  /*  if ((model->getMatrice()[left_x][left_y] == 1)&&(model->getMatrice()[down_x][down_y] == 1))
    {x1+=ennemyspeed;y1+=ennemyspeed;}
    if ((model->getMatrice()[right_x][right_y] == 1)&&(model->getMatrice()[down_x][down_y] == 1))
    {x1-=ennemyspeed;y1+=ennemyspeed;}
    if ((model->getMatrice()[left_x][left_y] == 1)&&(model->getMatrice()[up_x][up_y] == 1))
    {x1+=ennemyspeed;y1-=ennemyspeed;}
    if ((model->getMatrice()[right_x][right_y] == 1)&&(model->getMatrice()[up_x][up_y] == 1))
    {x1-=ennemyspeed;y1-=ennemyspeed;}*/
    if((model->getMatrice()[up_x][up_y] != 1)&&(model->getMatrice()[left_x][left_y] != 1)&&(model->getMatrice()[right_x][right_y] != 1)&&(model->getMatrice()[down_x][down_y] != 1))
    {

        if(x1<model->camera.x){x1+=ennemyspeed;}
        if(x1>model->camera.x){x1-=ennemyspeed;}
        if(y1<model->camera.y){y1+=ennemyspeed;}
        if(y1>model->camera.y){y1-=ennemyspeed;}



       /* if(chrono<=2){
            y1+=ennemyspeed;
        }
        else if(chrono<=4){             // utilisation du temps pour débloquer le fantome
            x1-=ennemyspeed;
        }
        else if(chrono<=6){
            y1-=ennemyspeed;
        }
        else if(chrono<=8){
            x1+=ennemyspeed;
        }*/
    }
    CreateCube(1, 1, 4, x1, y1, 0);

    }

void Gameobject::Ghost2() {

    up_y = (int)y2 + 1;
    up_x =(int) x2;

    down_y =(int) y2 - 1;
    down_x =(int) x2;

    left_y =(int) y2;
    left_x =(int) x2 - 1;

    right_y =(int) y2;
    right_x =(int) x2 + 1;

    if (model->getMatrice()[up_x][up_y] == 1) { y2-= ennemyspeed; }
    if (model->getMatrice()[down_x][down_y] == 1) { y2 += ennemyspeed; }
    if ((model->getMatrice()[left_x][left_y] == 1)) {x2 += ennemyspeed;}
    if (model->getMatrice()[right_x][right_y] == 1) { x2 -= ennemyspeed;}
    /*  if ((model->getMatrice()[left_x][left_y] == 1)&&(model->getMatrice()[down_x][down_y] == 1))
      {x2+=ennemyspeed;y2+=ennemyspeed;}
      if ((model->getMatrice()[right_x][right_y] == 1)&&(model->getMatrice()[down_x][down_y] == 1))
      {x2-=ennemyspeed;y2+=ennemyspeed;}
      if ((model->getMatrice()[left_x][left_y] == 1)&&(model->getMatrice()[up_x][up_y] == 1))
      {x2+=ennemyspeed;y2-=ennemyspeed;}
      if ((model->getMatrice()[right_x][right_y] == 1)&&(model->getMatrice()[up_x][up_y] == 1))
      {x2-=ennemyspeed;y2-=ennemyspeed;}*/
    if((model->getMatrice()[up_x][up_y] != 1)&&(model->getMatrice()[left_x][left_y] != 1)&&(model->getMatrice()[right_x][right_y] != 1)&&(model->getMatrice()[down_x][down_y] != 1))
    {

        if(x2<model->camera.x){x2+=ennemyspeed;}
        if(x2>model->camera.x){x2-=ennemyspeed;}
        if(y2<model->camera.y){y2+=ennemyspeed;}
        if(y2>model->camera.y){y2-=ennemyspeed;}



        /* if(chrono<=2){
             y2+=ennemyspeed;
         }
         else if(chrono<=4){             // utilisation du temps pour débloquer le fantome
             x2-=ennemyspeed;
         }
         else if(chrono<=6){
             y2-=ennemyspeed;
         }
         else if(chrono<=8){
             x2+=ennemyspeed;
         }*/
    }
    CreateCube(1, 1, 4, x2, y2, 0);

}

void Gameobject::Ghost3() {

    up_y = (int)y3 + 1;
    up_x =(int) x3;

    down_y =(int) y3 - 1;
    down_x =(int) x3;

    left_y =(int) y3;
    left_x =(int) x3 - 1;

    right_y =(int) y3;
    right_x =(int) x3 + 1;


    if (model->getMatrice()[up_x][up_y] == 1) { y3-= ennemyspeed; }
    if (model->getMatrice()[down_x][down_y] == 1) { y3 += ennemyspeed; }
    if ((model->getMatrice()[left_x][left_y] == 1)) {x3 += ennemyspeed;}
    if (model->getMatrice()[right_x][right_y] == 1) { x3 -= ennemyspeed;}
    /*  if ((model->getMatrice()[left_x][left_y] == 1)&&(model->getMatrice()[down_x][down_y] == 1))
      {x3+=ennemyspeed;y3+=ennemyspeed;}
      if ((model->getMatrice()[right_x][right_y] == 1)&&(model->getMatrice()[down_x][down_y] == 1))
      {x3-=ennemyspeed;y3+=ennemyspeed;}
      if ((model->getMatrice()[left_x][left_y] == 1)&&(model->getMatrice()[up_x][up_y] == 1))
      {x3+=ennemyspeed;y3-=ennemyspeed;}
      if ((model->getMatrice()[right_x][right_y] == 1)&&(model->getMatrice()[up_x][up_y] == 1))
      {x3-=ennemyspeed;y3-=ennemyspeed;}*/
    if((model->getMatrice()[up_x][up_y] != 1)&&(model->getMatrice()[left_x][left_y] != 1)&&(model->getMatrice()[right_x][right_y] != 1)&&(model->getMatrice()[down_x][down_y] != 1))
    {

        if(x3<model->camera.x){x3+=ennemyspeed;}
        if(x3>model->camera.x){x3-=ennemyspeed;}
        if(y3<model->camera.y){y3+=ennemyspeed;}
        if(y3>model->camera.y){y3-=ennemyspeed;}



        /* if(chrono<=2){
             y3+=ennemyspeed;
         }
         else if(chrono<=4){             // utilisation du temps pour débloquer le fantome
             x3-=ennemyspeed;
         }
         else if(chrono<=6){
             y3-=ennemyspeed;
         }
         else if(chrono<=8){
             x3+=ennemyspeed;
         }*/
    }
    CreateCube(1, 1, 4, x3, y3, 0);

}

void Gameobject::Ghost4() {

    up_y = (int)y4 + 1;
    up_x =(int) x4;

    down_y =(int) y4 - 1;
    down_x =(int) x4;

    left_y =(int) y4;
    left_x =(int) x4 - 1;

    right_y =(int) y4;
    right_x =(int) x4 + 1;

    if (model->getMatrice()[up_x][up_y] == 1) { y4-= ennemyspeed; }
    if (model->getMatrice()[down_x][down_y] == 1) { y4 += ennemyspeed; }
    if ((model->getMatrice()[left_x][left_y] == 1)) {x4 += ennemyspeed;}
    if (model->getMatrice()[right_x][right_y] == 1) { x4 -= ennemyspeed;}
    /*  if ((model->getMatrice()[left_x][left_y] == 1)&&(model->getMatrice()[down_x][down_y] == 1))
      {x4+=ennemyspeed;y4+=ennemyspeed;}
      if ((model->getMatrice()[right_x][right_y] == 1)&&(model->getMatrice()[down_x][down_y] == 1))
      {x4-=ennemyspeed;y4+=ennemyspeed;}
      if ((model->getMatrice()[left_x][left_y] == 1)&&(model->getMatrice()[up_x][up_y] == 1))
      {x4+=ennemyspeed;y4-=ennemyspeed;}
      if ((model->getMatrice()[right_x][right_y] == 1)&&(model->getMatrice()[up_x][up_y] == 1))
      {x4-=ennemyspeed;y4-=ennemyspeed;}*/
    if((model->getMatrice()[up_x][up_y] != 1)&&(model->getMatrice()[left_x][left_y] != 1)&&(model->getMatrice()[right_x][right_y] != 1)&&(model->getMatrice()[down_x][down_y] != 1))
    {

        if(x4<model->camera.x){x4+=ennemyspeed;}
        if(x4>model->camera.x){x4-=ennemyspeed;}
        if(y4<model->camera.y){y4+=ennemyspeed;}
        if(y4>model->camera.y){y4-=ennemyspeed;}



        /* if(chrono<=2){
             y4+=ennemyspeed;
         }
         else if(chrono<=4){             // utilisation du temps pour débloquer le fantome
             x4-=ennemyspeed;
         }
         else if(chrono<=6){
             y4-=ennemyspeed;
         }
         else if(chrono<=8){
             x4+=ennemyspeed;
         }*/
    }
    CreateCube(1, 1, 4, x4, y4, 0);

}


Gameobject::~Gameobject() {
	std::cout << "Destructeur de gameobject" << std::endl;
};