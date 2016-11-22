//
// Created by Valentin on 20/11/2016.
//

#ifndef PACMAN_OBJECT_H
#define PACMAN_OBJECT_H


#include <GL/gl.h>
#include "../model/Model.h"

class Object {
protected:
	Model *model;
	PosObjet position;
	unsigned int nb_texture = 0;
	sf::Image *img_tex = NULL;
	GLuint *Texture = NULL;

	void CreateTexture(sf::String repertoire, unsigned int nb_texture);

	void LoadTexture(unsigned int num_texture);

public:

	Object(Model *model);

	virtual ~Object();

	void SetPosition(int x, int y);

	void SetPosition(int x, int y, int z);

	void SetPosition(float x, float y);

	void SetPosition(float x, float y, float z);

	PosObjet &getPosition();

	void PreLoadTexture(unsigned int num_texture);
};


#endif //PACMAN_OBJECT_H
