//
// Created by Valentin on 28/10/2016.
//

#ifndef PACMAN_MODEL_H
#define PACMAN_MODEL_H

#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/VideoMode.hpp>

struct Camera {
	double x, y, z = 0;
	float eyeX, eyeY, eyeZ = 0;
};

struct Pos {
	float x, y, z = 0;
};

class Model {
private:
	sf::Font font;
	bool debug;
	float vitesseDep;

	void InitFont();

public:
	Camera camera;
	Pos pos;

	Model(bool debug = false);

	bool isDebug() const;

	sf::Font &getFont();

	float getVitesseDep();

	sf::VideoMode getResolution();

	//std::ifstream LoadMap(sf::String nomFichier);

    ~Model();
};

#endif //PACMAN_MODEL_H
