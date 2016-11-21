//
// Created by Valentin on 28/10/2016.
//

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include <SFML/Audio.hpp>
#include "Controller.h"

const double PI = 3.141592653589;

Controller::Controller(sf::RenderWindow &window, Model *model) : window(window) {
	this->model = model;
}

void Controller::ActionEvent(sf::Time time) {
	sf::Event event;

	while (window.pollEvent(event)) {

		// évènement "fermeture demandée" : on ferme la fenêtre
		if (event.type == sf::Event::Closed ||
			(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
			window.close();
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			//model->camera.x = sf::Mouse::getPosition(window).x * 0.3;
		}
		// Position relative inexistante dans SFML, donc déplacement du pointeur pour émulation

		// Faire le système "plus propre" au lieu de modifier la position de la souris "bord/bord" prendre le milieu de l'écran pour éviter tout problème (ex : Rustine)
		int Rustine = 1;

		if (sf::Mouse::getPosition(window).x <= 0 + Rustine) {
			sf::Mouse::setPosition(
					sf::Vector2i(window.getSize().x - (Rustine + Rustine), sf::Mouse::getPosition(window).y), window);
		}
		if (((unsigned) sf::Mouse::getPosition(window).x) >= window.getSize().x - Rustine) {
			sf::Mouse::setPosition(sf::Vector2i(0 + Rustine + Rustine, sf::Mouse::getPosition(window).y), window);
		}

		model->camera.eyeX =
				((-sf::Mouse::getPosition(window).x + (float) window.getSize().x / 2) / (float) window.getSize().x) *
				360;
		model->camera.eyeZ = model->camera.z + ((-sf::Mouse::getPosition(window).y + (float) window.getSize().y / 2) /
												(float) window.getSize().y) * 4;

		//std::cout << sf::Mouse::getPosition(window).x << window.getSize().x << std::endl;

		MoveKeyPressed(event, time.asSeconds());
	}
	//MoveKeyPressed(event, time.asSeconds());
	// Évite/(Réduit) le temps d'attente système pour la répétition d'une touche (Temporaire, ne fonctionne que sur les architectures de faible puissance)

}

void Controller::MoveKeyPressed(sf::Event event, float myftime) {
	float tempx = model->camera.x;
	float tempy = model->camera.y;

	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Left) {
			model->camera.y += model->getVitesseDep() * myftime * sin((model->camera.eyeX - 90) * PI / 180.0);
			model->camera.x += model->getVitesseDep() * myftime * cos((model->camera.eyeX - 90) * PI / 180.0);
		}

		if (event.key.code == sf::Keyboard::Right) {
			model->camera.y -= model->getVitesseDep() * myftime * sin((model->camera.eyeX - 90) * PI / 180.0);
			model->camera.x -= model->getVitesseDep() * myftime * cos((model->camera.eyeX - 90) * PI / 180.0);
		}

		if (event.key.code == sf::Keyboard::Up) {
			model->camera.y -= model->getVitesseDep() * myftime * sin(model->camera.eyeX * PI / 180.0);
			model->camera.x -= model->getVitesseDep() * myftime * cos(model->camera.eyeX * PI / 180.0);
		}

		if (event.key.code == sf::Keyboard::Down) {
			//model->camera.x += model->getVitesseDep() * myftime/** ellapsed_time*/;
			model->camera.y += model->getVitesseDep() * myftime * sin(model->camera.eyeX * PI / 180.0);
			model->camera.x += model->getVitesseDep() * myftime * cos(model->camera.eyeX * PI / 180.0);
		}
	}

	if (Speedpick) {
		model->ResetSpeed();
		if (model->getVitesseDep() == 30) {
			Speedpick = false;
		}
	}

	// mur bleu
	int pos_y = (int) ceilf(model->camera.y);
	int pos_x = (int) ceilf(model->camera.x);
	ramassePiece(pos_x, pos_y);


	if (model->getMatrice()[pos_x][pos_y] == 1) {
		model->camera.x = tempx;
		model->camera.y = tempy;
	}

	// mur rouge
	int pos_y2 = (int) floor(model->camera.y);
	int pos_x2 = (int) floor(model->camera.x);
	ramassePiece(pos_x2, pos_y2);


	if (model->getMatrice()[pos_x2][pos_y2 - 1] == 1) {
		model->camera.x = tempx;
		model->camera.y = tempy;
	}

	// mur vert
	int pos_y3 = (int) ceilf(model->camera.y);
	int pos_x3 = (int) floor(model->camera.x);
	ramassePiece(pos_x3, pos_y3);


	if (model->getMatrice()[pos_x3 - 1][pos_y3] == 1) {
		model->camera.x = tempx;
		model->camera.y = tempy;
	}

	// mur jaune
	int pos_y4 = (int) floor(model->camera.y);
	int pos_x4 = (int) ceilf(model->camera.x);
	ramassePiece(pos_x4, pos_y4);

	if (model->getMatrice()[pos_x4][pos_y4] == 1) {
		model->camera.x = tempx;
		model->camera.y = tempy;
	}

}

void Controller::ramassePiece(int x, int y) {

	if (model->getMatrice()[x][y] == 2) {
		model->setMatrice(x, y, 0);
		model->JoueSoundPiece();
		compteur++;
	}
	if (model->getMatrice()[x][y] == 3) {
		model->setMatrice(x, y, 0);
		model->JoueSoundPiece();
		model->setDepart();
		model->setVitesseDep(model->getVitesseDep() + 20.0f);
		model->ChangePitch(1.5);
		Speedpick = true;
	}
}

int Controller::GetCompteur() {
	return compteur;
}

Controller::~Controller() {
	std::cout << "Destructeur de controleur" << std::endl;
}

