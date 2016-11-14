#include <string.h>
#include "../model/Model.h"

class Gameobject {
private:
	Model *model;
	sf::Color color;
	float CoinHeight = 1;

public:
	Gameobject(Model *model);

	void CreateCoin(double x, double y);

	void CreateCube(float longueur, float largeur, float hauteur, int x, int y, int z);

	void CreateSol();

	/*void CreateMatrix(sf::Image image);*/

	~Gameobject();

	void GenerateMap();
};

