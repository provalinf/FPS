//
// Created on 19/11/2016.
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
	sf::Time TempsFramePrecedente;

	int correction;
	float ennemyspeed;

	bool Eat = false;

	float memposx = 0;
	float memposy = 0;
	int alea = 0;

	void toString();

	void CreateCube(float longueur, float largeur, float hauteur, float x, float y, float z);

	void GenerateEnemyAlgoAleatoire();

	void GenerateEnemyObj();

	void GenerateVector(obj_vector *v);

	void GenerateNormal(obj_vector *n);

	void GenerateTexture(obj_vector *t);

	void printVector(obj_vector *v);

	void CorrectifObj();

	void GenerateEnemyAlgoTracker();

public:

	Enemy(Model *model);

	~Enemy();

	void EnemyLoadObj(const char *ObjFile, int correction);

	void GenerateEnemy(int choix);

	bool isEat();
};


#endif //PACMAN_ENEMY_H
