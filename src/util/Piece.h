//
// Created by Valentin on 20/11/2016.
//

#ifndef PACMAN_PIECE_H
#define PACMAN_PIECE_H

#include "Object.h"

class Piece : public Object {
public:
	Piece(Model *model);

	void CreateCoin(int x, int y);

	void CreateSpeedCoin(int x, int y);

	~Piece();
};


#endif //PACMAN_PIECE_H
