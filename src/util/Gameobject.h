#include <string.h>

class Gameobject {
private:
	sf::Image image;
	sf::Color color;
    float CoinHeight = 1;

public:
	Gameobject();

    void CreateCoin(double x, double y);

	void CreateCube(float longueur, float largeur, float hauteur, int x, int y, int z);

	void CreateSol();

    void CreateMatrix(sf::Image image, int *pointeurmap);

	void CreateMap(int *pointeurmap);

	~Gameobject();

};

