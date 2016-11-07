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
	camera.z = 8;
	vitesseDep = 60.f;
}

/*Model::Model(bool debug) {	// Surcharge de constructeur inutile, valeur par défaut pour param disponible en C++
	//this(); ou équivalent apparemment impossible en C++
	this->debug = debug;
}*/

void Model::InitFont() {
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "/!\\ Erreur chargement font \"arial.ttf\"" << std::endl;
	}
}

std::ifstream Model::LoadMap(sf::String nomFichier) {
	std::ifstream map(nomFichier, std::ios::in);
	return map;
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