//
// Created by Valentin on 28/10/2016.
//

#ifndef PACMAN_MODEL_H
#define PACMAN_MODEL_H

#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Audio.hpp>

struct Camera {
	float x, y, z = 0.0f;
	float eyeX, eyeZ = 0.0f;
};

struct Map {
	unsigned int x, y = 0;
};

class Model {
private:
	sf::Font font;
	bool debug;
	float vitesseDep;

    time_t depart, arrivee;

	void InitFont();

	sf::Color color;

	sf::SoundBuffer buf_SoundPiece;
	sf::Sound Sound_piece;

    sf::Music music;

	int **matrice;

	void DefineTailleMap(sf::Image image);

public:
	Camera camera;
	Map map;
	int piece_height;

	Model(bool debug = false);

	bool isDebug() const;

	sf::Font &getFont();

	float getVitesseDep();

	sf::VideoMode getResolution();

	sf::Image LoadImgMap(sf::String nomFichier);

	Map &getMap();

	void CreateMatrix(sf::Image image);

	int **getMatrice();

	void setMatrice(int x, int y, int val);

	void DestructionMatrix();

	void InitialiseSoundPiece(sf::String nomFichier);

	void JoueSoundPiece();

	~Model();

    float setVitesseDep(float acc);

    void Loadmusic();

    void ChangePitch(float val);

    void ResetSpeed();

    time_t setDepart();
};

#endif //PACMAN_MODEL_H
