//
// Created by Valentin on 20/11/2016.
//

#ifndef PACMAN_PIECE_H
#define PACMAN_PIECE_H

#include "Object.h"

class Piece : public Object {
	sf::RenderWindow &window;

public:
	Piece(Model *model, sf::RenderWindow &window);

	~Piece();

	void CreateCoin(int x, int y);

	void CreateSpeedCoin(int x, int y);

	void CreatePieceMiniMap(int x, int y, sf::Uint8 R, sf::Uint8 V, sf::Uint8 B, sf::Uint8 A = 255);
};


#endif //PACMAN_PIECE_H
