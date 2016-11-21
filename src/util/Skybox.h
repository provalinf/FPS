//
// Created by Valentin on 20/11/2016.
//

#ifndef PACMAN_SKYBOX_H
#define PACMAN_SKYBOX_H


#include <GL/gl.h>
#include <SFML/Graphics/Image.hpp>
#include "Object.h"
#include "../model/Model.h"


class Skybox : public Object {
	int longueur, largeur, hauteur;

public:

	Skybox(Model *model);

	~Skybox();

	void GenerateSkyBox();

};


#endif //PACMAN_SKYBOX_H
