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

	//LoadTexture(0);
    glColor3ub(254, 236, 14);
	GLUquadricObj *quadra = gluNewQuadric();

	glPushMatrix();
	glTranslatef(x, y, model->getHauteurPiece());
    glRotatef(90,1,0,0);
    glRotatef(clock(),0,1,0);
    gluCylinder(quadra,0.2,0.2,0.1,80,1);
    gluDisk(quadra,0,0.2,30,30);
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

Piece::~Piece() {
	std::cout << "Destructeur de piece" << std::endl;
}
