//
// Created by Valentin on 19/11/2016.
//

#ifndef PACMAN_ENEMY_H
#define PACMAN_ENEMY_H


#include <SFML/System/String.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "LibObj/objLoader.h"
#include "LibObj/obj_parser.h"
#include "../model/Model.h"
#include "Object.h"

class Enemy : public Object {

	objLoader *objData = NULL;

	void toString();

	void CreateCube(float longueur, float largeur, float hauteur, float x, float y, float z);

	void GenerateEnemyCube();

	void GenerateEnemyObj();

	void GenerateVector(obj_vector *v);

	void GenerateNormal(obj_vector *n);

	void GenerateTexture(obj_vector *t);

	void printVector(obj_vector *v);

public:

	Enemy(Model *model);

	~Enemy();

	void EnemyLoadObj(const char *ObjFile);

	void GenerateEnemy();

	int up_y;
	int up_x;
	int down_y;
	int down_x;
	int left_y;
	int left_x;
	int right_y;
	int right_x;
	int y1 = 2;
	int x1 = 4;
	float ennemyspeed = 0.07;
};


#endif //PACMAN_ENEMY_H
