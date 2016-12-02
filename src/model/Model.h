//
// Created by Valentin on 28/10/2016.
//

#ifndef PACMAN_MODEL_H
#define PACMAN_MODEL_H

#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

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

struct BoutonMenu {
	int x = 0, y = 0;
	int longueur = 0, largeur = 0;
	sf::RectangleShape background;
	sf::Text texte;
};

class Model {
private:
	sf::Font font;
	bool debug;

	float vitesseDep;
	int piece_height;
	int nombreDePieces = 0;

	sf::Clock ClockFrame;
	sf::Color color;

	sf::SoundBuffer buf_SoundPiece;
	sf::Sound Sound_piece;
	sf::Music music;

	sf::SoundBuffer buff_SoundFreeze;
	sf::Sound Sound_Freeze;

	sf::SoundBuffer buff_SoundDeFreeze;
	sf::Sound Sound_DeFreeze;

	sf::SoundBuffer buff_SoundTP;
	sf::Sound Sound_TP;

	bool jeu_active;


	bool Freeze = false;
	bool MangerEnnemis = false;

	int **matrice;
	CoordMap map;
	int nbFreezeDispo = 0;

	void DefineTailleMap(sf::Image image);

public:
	Camera camera;

	Model(bool debug = false);

	~Model();

	bool isDebug() const;

	sf::Font &getFont();

	float getVitesseDep();

	void setVitesseDep(float acc);

	void ResetVitesseDep();

	sf::VideoMode getResolution();

	sf::Image LoadImgMap(sf::String nomFichier);

	CoordMap &getMap();

	void CreateMatrix(sf::Image image);

	int **getMatrice();

	void setMatrice(int x, int y, int val);

	void DestructionMatrix();

	int getHauteurPiece();

	int getNombreTotalPiece();

	void IncremNombreTotalPiece();

	void InitialiseSoundPiece(sf::String nomFichier);

	void JoueSoundPiece();

	void InitialiseMusic(sf::String nomFichier);

	void LanceMusic();

	void ChangeMusicPitch(float val);

	void ResetMusicPitch();

	std::string toString(int integer);

	std::string toString(double dble);

	std::string toString(float flt);

	bool GetFreeze();

	void SetFreeze(bool etat);

	void JoueSoundFreeze();

	void InitialiseSoundFreeze(sf::String nomFichier);

	float getDeltaTimeFrame(sf::Time FramePrec);

	void InitFont(sf::String nomFichier);

	const int getTailleMiniMap() const;
	sf::Time getTimeFrame();

	void InitialiseSoundTP(sf::String nomFichier);

	void JoueSoundTP();

	bool isJeu_active();

	void setJeu_active(bool jeu_active);

	bool isMangerEnnemis();

	void setMangerEnnemis(bool MangerEnnemis);

	int getNbFreezeDispo();

	void IncNbFreezeDispo();

	void DecNbFreezeDispo();

	void InitialiseSoundDeFreeze(sf::String nomFichier);

	void JoueSoundDeFreeze();
};

#endif //PACMAN_MODEL_H
