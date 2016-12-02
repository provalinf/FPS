//
// Created by Valentin on 28/10/2016.
//

#include <iostream>
#include <fstream>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include "Model.h"

const float vitesseDepDefaut = 0.6f;
const int TailleMiniMap = 3;

const sf::String REP_FONT = "Font";
const sf::String REP_FX = "Fx";
const sf::String REP_IMG = "Img";
const sf::String REP_MATRICE = "Matrice";
const sf::String REP_MUSIC = "Music";
const char *REP_OBJ = "Obj";

Model::Model(bool debug) {
	this->debug = debug;
	InitFont("arial.ttf");
	InitialiseMusic("music.wav");
	InitialiseSoundPiece("ramassepiece.wav");
	InitialiseSoundFreeze("freeze.wav");
	InitialiseSoundDeFreeze("defreeze.wav");
	InitialiseSoundTP("TPsound.wav");

	jeu_active = false;
	piece_height = 1;
	camera.x = 18;
	camera.y = 20;

	camera.z = 1.5;    // Défaut : 1.5
	camera.eyeZ = camera.z;
	ResetVitesseDep();
}

/*Model::Model(bool debug) {	// Surcharge de constructeur inutile, valeur par défaut pour param disponible en C++
	//this(); ou équivalent apparemment impossible en C++
	this->debug = debug;
}*/

void Model::InitFont(sf::String nomFichier) {
	nomFichier = REP_FONT + "/" + nomFichier;
	if (!font.loadFromFile(nomFichier)) {
		std::cout << "/!\\ Failure to load font : " << nomFichier.toAnsiString() << std::endl;
		std::exit(1);
	}
}


bool Model::isJeu_active() {
	return jeu_active;
}

bool Model::isMangerEnnemis() {
	return MangerEnnemis;
}

int Model::getNbFreezeDispo() {
	return nbFreezeDispo;
}

void Model::IncNbFreezeDispo() {
	Model::nbFreezeDispo++;
}

void Model::DecNbFreezeDispo() {
	if (nbFreezeDispo > 0) {
		nbFreezeDispo--;
	}
}

void Model::setMangerEnnemis(bool MangerEnnemis) {
	Model::MangerEnnemis = MangerEnnemis;
}

void Model::setJeu_active(bool jeu_active) {
	Model::jeu_active = jeu_active;
}

sf::Image Model::LoadImgMap(sf::String nomFichier) {
	nomFichier = REP_MATRICE + "/" + nomFichier;
	sf::Image map_image;
	if (!map_image.loadFromFile(nomFichier)) {
		std::cout << "/!\\ Failure to load map : " << nomFichier.toAnsiString() << std::endl;
		std::exit(1);
	}
	return map_image;
}

void Model::DefineTailleMap(sf::Image image) {
	map.x = image.getSize().x;
	map.y = image.getSize().y;
}

CoordMap &Model::getMap() {
	return map;
}

void Model::CreateMatrix(sf::Image image) {
	DefineTailleMap(image);
	matrice = new int *[map.x];
	for (unsigned int i = 0; i < map.x; ++i) {
		matrice[i] = new int[map.y];
	}

	for (unsigned int x = 0; x < map.x; x++) {
		for (unsigned int y = 0; y < map.y; y++) {
			if (image.getPixel(x, y) == color.Black) {			// Murs
				matrice[x][y] = 1;
			} else if (image.getPixel(x, y) == color.White) {	// Vide
				matrice[x][y] = 0;
			} else if (image.getPixel(x, y) == color.Red) {		// Pièces
				matrice[x][y] = 2;
				IncremNombreTotalPiece();
			} else if (image.getPixel(x, y) == color.Green) {	// Boost
				matrice[x][y] = 3;
			} else if (image.getPixel(x, y) == color.Yellow) {	// Télép
				matrice[x][y] = 4;
			} else if (image.getPixel(x, y) == color.Blue) {	// Manger ennemis
				matrice[x][y] = 5;
			} else if (image.getPixel(x, y) == color.Magenta) {	// Manger ennemis
				matrice[x][y] = 6;
			}
		}
	}
}

void Model::DestructionMatrix() {
	for (unsigned int i = 0; i < map.x; ++i) {
		delete matrice[i];
	}
	delete matrice;
}

int **Model::getMatrice() {
	return matrice;
}

void Model::setMatrice(int x, int y, int val) {
	Model::matrice[x][y] = val;
}

bool Model::isDebug() const {
	return debug;
}

const int Model::getTailleMiniMap() const {
	return TailleMiniMap;
}

sf::Font &Model::getFont() {
	return font;
}

float Model::getDeltaTimeFrame(sf::Time FramePrec) {
	return ClockFrame.getElapsedTime().asMilliseconds() - FramePrec.asMilliseconds();
}

sf::Time Model::getTimeFrame() {
	return ClockFrame.getElapsedTime();
}

float Model::getVitesseDep() {
	return vitesseDep;
}

void Model::setVitesseDep(float v) {
	vitesseDep = v;
}

void Model::ResetVitesseDep() {
	vitesseDep = vitesseDepDefaut;
}

int Model::getHauteurPiece() {
	return piece_height;
}

int Model::getNombreTotalPiece() {
	return nombreDePieces;
}

void Model::IncremNombreTotalPiece() {
	nombreDePieces++;
}

sf::VideoMode Model::getResolution() {
	return sf::VideoMode::getDesktopMode();
}

void Model::InitialiseSoundTP(sf::String nomFichier) {
	nomFichier = REP_FX + "/" + nomFichier;
	if (!buff_SoundTP.loadFromFile(nomFichier)) {
		std::cout << "/!\\ Failure to load sound TP : " << nomFichier.toAnsiString() << std::endl;
		std::exit(1);
	}
	Sound_TP = sf::Sound(buff_SoundTP);
	Sound_TP.setPitch(1.2);
}


void Model::InitialiseSoundPiece(sf::String nomFichier) {
	nomFichier = REP_FX + "/" + nomFichier;
	if (!buf_SoundPiece.loadFromFile(nomFichier)) {
		std::cout << "/!\\ Failure to load sound coin : " << nomFichier.toAnsiString() << std::endl;
		std::exit(1);
	}
	Sound_piece = sf::Sound(buf_SoundPiece);
	Sound_piece.setPitch(1.2);
}

void Model::InitialiseSoundFreeze(sf::String nomFichier) {
	nomFichier = REP_FX + "/" + nomFichier;
	if (!buff_SoundFreeze.loadFromFile(nomFichier)) {
		std::cout << "/!\\ Failure to load sound freeze : " << nomFichier.toAnsiString() << std::endl;
		std::exit(1);
	}
	Sound_Freeze = sf::Sound(buff_SoundFreeze);
	Sound_Freeze.setPitch(0.9);
}

void Model::InitialiseSoundDeFreeze(sf::String nomFichier) {
	nomFichier = REP_FX + "/" + nomFichier;
	if (!buff_SoundDeFreeze.loadFromFile(nomFichier)) {
		std::cout << "/!\\ Failure to load sound freeze : " << nomFichier.toAnsiString() << std::endl;
		std::exit(1);
	}
	Sound_DeFreeze = sf::Sound(buff_SoundDeFreeze);
	Sound_DeFreeze.setPitch(0.9);
}

void Model::JoueSoundTP(){
	Sound_TP.play();
}
void Model::JoueSoundPiece() {
	Sound_piece.play();
}

void Model::JoueSoundFreeze() {
	Sound_Freeze.play();
}

void Model::JoueSoundDeFreeze() {
	Sound_DeFreeze.play();
}

void Model::InitialiseMusic(sf::String nomFichier) {
	nomFichier = REP_MUSIC + "/" + nomFichier;
	if (!music.openFromFile(nomFichier)) {
		std::cout << "/!\\ Failure to load music : " << nomFichier.toAnsiString() << std::endl;
		std::exit(1);
	}
	music.setLoop(true);
}

void Model::LanceMusic() {
	music.play();
}

void Model::ChangeMusicPitch(float val) {
	music.setPitch(val);
}

void Model::ResetMusicPitch() {
	music.setPitch(1);
}

std::string Model::toString(double dble) {
	std::ostringstream os;
	os << dble;
	return os.str();
}

std::string Model::toString(float flt) {
	std::ostringstream os;
	os << flt;
	return os.str();
}

std::string Model::toString(int integer) {
	std::ostringstream os;
	os << integer;
	return os.str();
}

bool Model::GetFreeze() {
	return Freeze;
}

void Model::SetFreeze(bool etat) {
	Freeze = etat;
}

Model::~Model() {
	std::cout << "Destructeur de model" << std::endl;
	DestructionMatrix();
}