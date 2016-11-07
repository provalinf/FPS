#include <string.h>

class Gameobject {
private:
    sf::Image image;
    sf::Color color;

public:
	Gameobject();

	void CreateCube(float longueur, float largeur, float hauteur, int x, int y, int z);

	void CreateSol();

    void CreateMap(sf::Image image);

    ~Gameobject();

};

