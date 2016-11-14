#include <GL/gl.h>
#include <iostream>
#include <SFML/Graphics/Texture.hpp>
#include <GL/glu.h>
#include "Gameobject.h"


Gameobject::Gameobject(Model *model) {
	this->model = model;
}

void Gameobject::CreateCoin(int x, int y) {

	glColor3ub(255, 0, 0);
	GLUquadricObj *quadra = gluNewQuadric();
	glPushMatrix();
	glTranslatef(x, y, model->piece_height);
	gluSphere(quadra, 0.1, 5, 5);
	glPopMatrix();
	gluDeleteQuadric(quadra);
}

void Gameobject::CreateCube(float longueur, float largeur, float hauteur, int x, int y, int z) {

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
				CreateCube(1, 1, 4, x, y, 0);
			} else if (model->getMatrice()[x][y] == 2) {
				CreateCoin(x, y);
			}
		}
	}
}

Gameobject::~Gameobject() {
	std::cout << "Destructeur de gameobject" << std::endl;
};