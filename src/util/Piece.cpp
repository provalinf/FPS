//
// Created by Valentin on 20/11/2016.
//

#include <GL/glu.h>
#include <iostream>
#include "Piece.h"

Piece::Piece(Model *model) : Object(model) {
	CreateTexture("Coin", 1);
}

void Piece::CreateCoin(int x, int y) {

	glColor3ub(226, 144, 0);
	GLUquadricObj *quadra = gluNewQuadric();

	glPushMatrix();
	glTranslatef(x, y, model->getHauteurPiece());
	glRotatef(180, 0, 1, 0);
	glRotatef(90, 1, 0, 0);
	glRotatef(clock() / 2, 0, 1, 0);
	gluCylinder(quadra, 0.2, 0.2, 0.1, 80, 1);
	glColor3ub(0, 236, 14);

	LoadTexture(0);
	gluQuadricTexture(quadra, GL_TRUE);
	gluDisk(quadra, 0, 0.2, 30, 30);

	glRotatef(180, 0, 1, 0);
	glTranslated(0, 0, -0.1);
	gluDisk(quadra, 0, 0.2, 30, 30);
	glDisable(GL_TEXTURE_2D);
	//gluSphere(quadra, 0.3, 10, 10);
	glPopMatrix();
	gluDeleteQuadric(quadra);
}

void Piece::CreateSpeedCoin(int x, int y) {
	glColor3ub(0, 0, 0);
	GLUquadricObj *quadra = gluNewQuadric();
	glPushMatrix();
	glTranslatef(x, y, model->getHauteurPiece());
	gluSphere(quadra, 0.5, 10, 10);
	glPopMatrix();
	gluDeleteQuadric(quadra);
}

void Piece::CreateEatCoin(int x, int y) {
	glColor3ub(100, 100, 255);
	GLUquadricObj *quadra = gluNewQuadric();
	glPushMatrix();
	glTranslatef(x, y, model->getHauteurPiece());
	gluSphere(quadra, 0.5, 10, 10);
	glPopMatrix();
	gluDeleteQuadric(quadra);
}

Piece::~Piece() {
	std::cout << "Destructeur de piece" << std::endl;
}
