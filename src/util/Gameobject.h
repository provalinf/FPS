#include <string.h>

class Gameobject {
private:
	sf::Image image;
	sf::Color color;
    float CoinHeight = 0.5;

public:
	Gameobject();

    void CreateCoin(double x, double y);

	void CreateCube(float longueur, float largeur, float hauteur, int x, int y, int z);

	void CreateSol();

	void CreateMap(sf::Image image);

	~Gameobject();

};

