//
// Created by Valentin on 20/11/2016.
//

#include <GL/gl.h>
#include <iostream>
#include "Map.h"

Map::Map(Model *model, sf::String nomMap) : Object(model) {
	pieces = new Piece(model);
	model->CreateMatrix(model->LoadImgMap(nomMap));
}

void Map::GenerateMap() {
	for (unsigned int x = 0; x < model->getMap().x; x++) {
		for (unsigned int y = 0; y < model->getMap().y; y++) {
			if (model->getMatrice()[x][y] == 1) {
				CreateCube(1, 1, 4, x, y, 0);
			} else if (model->getMatrice()[x][y] == 2) {
				pieces->CreateCoin(x, y);
			} else if (model->getMatrice()[x][y] == 3) {
				pieces->CreateSpeedCoin(x, y);
			}
		}
	}
}

void Map::CreateCube(float longueur, float largeur, float hauteur, float x, float y, float z) {

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

Map::~Map() {
	std::cout << "Destructeur de map" << std::endl;
	delete (pieces);
}

