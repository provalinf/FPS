//
// Created by Valentin on 28/10/2016.
//

#ifndef PACMAN_MODEL_H
#define PACMAN_MODEL_H

#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/VideoMode.hpp>

struct Camera {
	float x, y, z = 0.0f;
	float eyeX, eyeY, eyeZ = 0.0f;
};

struct Map {
	int x, y = 0;
};

class Model {
private:
	sf::Font font;
	bool debug;
	float vitesseDep;

	void InitFont();

	sf::Color color;
	int **matrice;

	void DefineTailleMap(sf::Image image);

public:
	Camera camera;
	Map map;

	Model(bool debug = false);

	bool isDebug() const;

	sf::Font &getFont();

	float getVitesseDep();

	sf::VideoMode getResolution();

	//std::ifstream LoadMap(sf::String nomFichier);

	~Model();

	void CreateMatrix(sf::Image image);

	int **getMatrice();

	Map &getMap();

	void DestructionMatrix();
};

#endif //PACMAN_MODEL_H
