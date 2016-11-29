//
// Created by Valentin on 20/11/2016.
//

#include <GL/glu.h>
#include <iostream>
#include "Piece.h"

Piece::Piece(Model *model) : Object(model) {
	CreateTexture("Obj",1);
}

void Piece::CreateCoin(int x, int y) {

	//glColor3ub(157, 0, 157);
	LoadTexture(0);
	GLUquadricObj *quadra = gluNewQuadric();
	glPushMatrix();
	glTranslatef(x, y, model->getHauteurPiece());
	gluSphere(quadra, 0.3, 10, 10);
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

Piece::~Piece() {
	std::cout << "Destructeur de piece" << std::endl;
}
