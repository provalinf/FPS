//
// Created by Valentin on 28/10/2016.
//

#include <iostream>
#include <fstream>
#include <SFML/Window/VideoMode.hpp>
#include "Model.h"

Model::Model(bool debug) {
	this->debug = debug;
	InitFont();
	piece_height = 1;
	camera.x = 20;
	camera.y = 20;

	camera.z = 10.5;	// Défaut : 1.5
	camera.eyeZ = camera.z;
	vitesseDep = 10.f;
}

/*Model::Model(bool debug) {	// Surcharge de constructeur inutile, valeur par défaut pour param disponible en C++
	//this(); ou équivalent apparemment impossible en C++
	this->debug = debug;
}*/

void Model::InitFont() {
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "/!\\ Erreur chargement font \"arial.ttf\"" << std::endl;
		std::exit(1);
	}
}

sf::Image Model::LoadImgMap(sf::String nomFichier) {
	sf::Image map_image;
	if (!map_image.loadFromFile(nomFichier)) {
		std::cout << "Failure to load map : " << nomFichier.toAnsiString() << std::endl;
		std::exit(1);
	}
	return map_image;
}

void Model::DefineTailleMap(sf::Image image) {
	map.x = image.getSize().x;
	map.y = image.getSize().y;
}

Map &Model::getMap() {
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
			if (image.getPixel(x, y) == color.Black) {
				matrice[x][y] = 1;
			} else if (image.getPixel(x, y) == color.White) {
				matrice[x][y] = 0;
			} else if (image.getPixel(x, y) == color.Red) {
				matrice[x][y] = 2;
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

bool Model::isDebug() const {
	return debug;
}

sf::Font &Model::getFont() {
	return font;
}

float Model::getVitesseDep() {
	return vitesseDep;
}

sf::VideoMode Model::getResolution() {
	return sf::VideoMode::getDesktopMode();
}

Model::~Model() {
	std::cout << "Destructeur de model" << std::endl;
	DestructionMatrix();
};