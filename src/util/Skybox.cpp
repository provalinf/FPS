//
// Created by Valentin on 20/11/2016.
//

#include <GL/gl.h>
#include <iostream>
#include "Skybox.h"

Skybox::Skybox(Model *model) : Object(model) {
	longueur = model->getMap().x;
	largeur = model->getMap().y;
	hauteur = 50;

	CreateTexture("Skybox", 6);
}

void Skybox::GenerateSkyBox() {

	LoadTexture(0);
	glBegin(GL_QUADS);
	//glColor3ub(255, 0, 0); //face rouge
	glTexCoord2d(1.0, 0.0);
	glVertex3d(position.fx + longueur, position.fy + largeur, position.fz + hauteur);
	glTexCoord2d(1.0, 1.0);
	glVertex3d(position.fx + longueur, position.fy + largeur, position.fz + 0);
	glTexCoord2d(0.0, 1.0);
	glVertex3d(position.fx + 0, position.fy + largeur, position.fz + 0);
	glTexCoord2d(0.0, 0.0);
	glVertex3d(position.fx + 0, position.fy + largeur, position.fz + hauteur);
	glEnd();

	LoadTexture(1);
	glBegin(GL_QUADS);
	//glColor3ub(0, 255, 0); //face verte
	glTexCoord2d(1.0, 0.0);
	glVertex3d(position.fx + longueur, position.fy + 0, position.fz + hauteur);
	glTexCoord2d(1.0, 1.0);
	glVertex3d(position.fx + longueur, position.fy + 0, position.fz + 0);
	glTexCoord2d(0.0, 1.0);
	glVertex3d(position.fx + longueur, position.fy + largeur, position.fz + 0);
	glTexCoord2d(0.0, 0.0);
	glVertex3d(position.fx + longueur, position.fy + largeur, position.fz + hauteur);
	glEnd();

	LoadTexture(2);
	glBegin(GL_QUADS);
	//glColor3ub(0, 0, 255); //face bleue
	glTexCoord2d(1.0, 0.0);
	glVertex3d(position.fx + 0, position.fy + 0, position.fz + hauteur);
	glTexCoord2d(1.0, 1.0);
	glVertex3d(position.fx + 0, position.fy + 0, position.fz + 0);
	glTexCoord2d(0.0, 1.0);
	glVertex3d(position.fx + longueur, position.fy + 0, position.fz + 0);
	glTexCoord2d(0.0, 0.0);
	glVertex3d(position.fx + longueur, position.fy + 0, position.fz + hauteur);
	glEnd();

	LoadTexture(3);
	glBegin(GL_QUADS);
	//glColor3ub(255, 255, 0); //face jaune
	glTexCoord2d(1.0, 0.0);
	glVertex3d(position.fx + 0, position.fy + largeur, position.fz + hauteur);
	glTexCoord2d(1.0, 1.0);
	glVertex3d(position.fx + 0, position.fy + largeur, position.fz + 0);
	glTexCoord2d(0.0, 1.0);
	glVertex3d(position.fx + 0, position.fy + 0, position.fz + 0);
	glTexCoord2d(0.0, 0.0);
	glVertex3d(position.fx + 0, position.fy + 0, position.fz + hauteur);
	glEnd();

	LoadTexture(4);
	glBegin(GL_QUADS);
	//glColor3ub(0, 255, 255); //face cyan (Bas)
	glTexCoord2d(10.0, 0.0);
	glVertex3d(position.fx + longueur, position.fy + largeur, position.fz + 0);
	glTexCoord2d(10.0, 10.0);
	glVertex3d(position.fx + longueur, position.fy + 0, position.fz + 0);
	glTexCoord2d(0.0, 10.0);
	glVertex3d(position.fx + 0, position.fy + 0, position.fz + 0);
	glTexCoord2d(0.0, 0.0);
	glVertex3d(position.fx + 0, position.fy + largeur, position.fz + 0);
	glEnd();

	LoadTexture(5);
	glBegin(GL_QUADS);
	//glColor3ub(255, 0, 255); //face magenta (Haut)
	glTexCoord2d(1.0, 0.0);
	glVertex3d(position.fx + longueur, position.fy + 0, position.fz + hauteur);
	glTexCoord2d(1.0, 1.0);
	glVertex3d(position.fx + longueur, position.fy + largeur, position.fz + hauteur);
	glTexCoord2d(0.0, 1.0);
	glVertex3d(position.fx + 0, position.fy + largeur, position.fz + hauteur);
	glTexCoord2d(0.0, 0.0);
	glVertex3d(position.fx + 0, position.fy + 0, position.fz + hauteur);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

Skybox::~Skybox() {
	std::cout << "Destructeur de skybox" << std::endl;
}
