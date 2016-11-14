#include <string.h>
#include "../model/Model.h"

class Gameobject {
private:
	Model *model;

public:
	Gameobject(Model *model);

	void CreateCoin(int x, int y);

	void CreateCube(float longueur, float largeur, float hauteur, int x, int y, int z);

	void CreateSol();

	~Gameobject();

	void GenerateMap();
};

