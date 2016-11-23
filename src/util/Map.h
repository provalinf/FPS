//
// Created by Valentin on 20/11/2016.
//

#ifndef PACMAN_CUBE_H
#define PACMAN_CUBE_H

#include "Piece.h"
#include "Object.h"

class Map : public Object {

	Piece *pieces;

public:
	Map(Model *model, sf::String nomMap);

	~Map();

	void GenerateMap();

	void CreateCube(float longueur, float largeur, float hauteur, float x, float y, float z);
};


#endif //PACMAN_CUBE_H
