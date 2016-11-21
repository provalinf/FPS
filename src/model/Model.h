//
// Created by Valentin on 28/10/2016.
//

#ifndef PACMAN_MODEL_H
#define PACMAN_MODEL_H

#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Audio.hpp>

struct Camera {
	float x = 0.0f, y = 0.0f, z = 0.0f;
	float eyeX = 0.0f, eyeZ = 0.0f;
};

struct CoordMap {
	unsigned int x = 0, y = 0;
};

struct PosObjet {
	unsigned int ix = 0, iy = 0, iz = 0;
	float fx = 0.0f, fy = 0.0f, fz = 0.0f;
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
	CoordMap map;
	int piece_height;

	Model(bool debug = false);

	bool isDebug() const;

	sf::Font &getFont();

	float getVitesseDep();

	sf::VideoMode getResolution();

	sf::Image LoadImgMap(sf::String nomFichier);

	CoordMap &getMap();

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

	std::string toString(int integer);
};

#endif //PACMAN_MODEL_H
