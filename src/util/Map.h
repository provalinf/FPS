//
// Created by Valentin on 20/11/2016.
//

#ifndef PACMAN_CUBE_H
#define PACMAN_CUBE_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "Piece.h"
#include "Object.h"

class Map : public Object {
	float TailleMiniMap;

public:
	Map(Model *model, sf::RenderWindow &window, sf::String nomMap);
	sf::RenderWindow &window;

	~Map();

	void CreateMur(float longueur, float largeur, float hauteur, float x, float y, float z);

	void CreateBlocMiniMap(int x, int y, sf::Uint8 R, sf::Uint8 V, sf::Uint8 B, sf::Uint8 A = 255);
};


#endif //PACMAN_CUBE_H
