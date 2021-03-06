//
// Created on 20/11/2016.
//

#include <iostream>
#include <GL/glu.h>
#include "Object.h"

Object::Object(Model *model) {
	this->model = model;
}

void Object::CreateTexture(sf::String repertoire, unsigned int nb_texture) {
	this->nb_texture = nb_texture;
	img_tex = new sf::Image[nb_texture];
	Texture = new GLuint[nb_texture];

	for (unsigned int i = 0; i < nb_texture; i++) {
		if (!img_tex[i].loadFromFile("img/" + repertoire + "/face" + model->toString((int) i + 1) + ".jpg")) {
			std::cout << "Erreur chargement img_tex pour texture img/" + repertoire.toAnsiString() + "/face" << i + 1
					  << ".jpg" << std::endl;
			std::exit(1);
		}
		PreLoadTexture(i);
	}
}

void Object::PreLoadTexture(unsigned int num_texture) {
	if (num_texture >= nb_texture) {
		std::cout << "Erreur, seul " << nb_texture << " sont disponibles" << std::endl;
		std::exit(1);
	}

	glGenTextures(1, &Texture[num_texture]);
	glBindTexture(GL_TEXTURE_2D, Texture[num_texture]);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, img_tex[num_texture].getSize().x, img_tex[num_texture].getSize().y, GL_RGBA,
					  GL_UNSIGNED_BYTE, img_tex[num_texture].getPixelsPtr());
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
}

void Object::LoadTexture(unsigned int num_texture) {
	glColor3d(255, 255, 255);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, Texture[num_texture]);
}

void Object::SetPosition(int x, int y) {
	SetPosition(x, y, position.iz);
}

void Object::SetPosition(int x, int y, int z) {
	position.ix = (unsigned int) x;
	position.iy = (unsigned int) y;
	position.iz = (unsigned int) z;
}

void Object::SetPosition(float x, float y) {
	SetPosition(x, y, position.fz);
}

void Object::SetPosition(float x, float y, float z) {
	position.fx = x;
	position.fy = y;
	position.fz = z;
}

PosObjet &Object::getPosition() {
	return position;
}

Object::~Object() {
	std::cout << "Destructeur de objet (appel polymorphique)" << std::endl;
	if (Texture != NULL) delete (Texture);
	if (img_tex != NULL) delete (img_tex);
}
