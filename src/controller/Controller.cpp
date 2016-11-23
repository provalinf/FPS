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

		if (event.type == sf::Event::Closed ||
			(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
			window.close();
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		}

		// Position relative inexistante dans SFML, donc déplacement du pointeur pour émulation
		if (sf::Mouse::getPosition(window).x <= 100) {
			sf::Mouse::setPosition(
					sf::Vector2i(window.getSize().x - 100, sf::Mouse::getPosition(window).y), window);
		}
		if (((unsigned) sf::Mouse::getPosition(window).x) >= window.getSize().x - 100) {
			sf::Mouse::setPosition(sf::Vector2i(100, sf::Mouse::getPosition(window).y), window);
		}

		model->camera.eyeX =
				((-sf::Mouse::getPosition(window).x + (float) (window.getSize().x - 200) / 2) /
				 (float) (window.getSize().x - 200)) *
				360;
		model->camera.eyeZ = model->camera.z + ((-sf::Mouse::getPosition(window).y + (float) window.getSize().y / 2) /
												(float) window.getSize().y) * 4;

		//std::cout << sf::Mouse::getPosition(window).x << window.getSize().x << std::endl;

		MoveKeyboard(event);
	}

	MoveKeyPressed(event, time);

}

void Controller::MoveKeyboard(sf::Event event) {
	if (event.type == sf::Event::KeyPressed) {
		Keyboard[0] = (event.key.code == sf::Keyboard::Left) ? true : Keyboard[0];
		Keyboard[1] = (event.key.code == sf::Keyboard::Right) ? true : Keyboard[1];
		Keyboard[2] = (event.key.code == sf::Keyboard::Up) ? true : Keyboard[2];
		Keyboard[3] = (event.key.code == sf::Keyboard::Down) ? true : Keyboard[3];
	}

	if (event.type == sf::Event::KeyReleased) {
		Keyboard[0] = (event.key.code == sf::Keyboard::Left) ? false : Keyboard[0];
		Keyboard[1] = (event.key.code == sf::Keyboard::Right) ? false : Keyboard[1];
		Keyboard[2] = (event.key.code == sf::Keyboard::Up) ? false : Keyboard[2];
		Keyboard[3] = (event.key.code == sf::Keyboard::Down) ? false : Keyboard[3];
	}

}


void Controller::MoveKeyPressed(sf::Event event, sf::Time myftime) {
	float tempx = model->camera.x;
	float tempy = model->camera.y;

	if (Keyboard[0]) {
		model->camera.y += model->getVitesseDep() * myftime.asSeconds() * sin((model->camera.eyeX - 90) * PI / 180.0);
		model->camera.x += model->getVitesseDep() * myftime.asSeconds() * cos((model->camera.eyeX - 90) * PI / 180.0);
	}
	if (Keyboard[1]) {
		model->camera.y -= model->getVitesseDep() * myftime.asSeconds() * sin((model->camera.eyeX - 90) * PI / 180.0);
		model->camera.x -= model->getVitesseDep() * myftime.asSeconds() * cos((model->camera.eyeX - 90) * PI / 180.0);
	}
	if (Keyboard[2]) {
		model->camera.y -= model->getVitesseDep() * myftime.asSeconds() * sin(model->camera.eyeX * PI / 180.0);
		model->camera.x -= model->getVitesseDep() * myftime.asSeconds() * cos(model->camera.eyeX * PI / 180.0);
	}
	if (Keyboard[3]) {
		model->camera.y += model->getVitesseDep() * myftime.asSeconds() * sin(model->camera.eyeX * PI / 180.0);
		model->camera.x += model->getVitesseDep() * myftime.asSeconds() * cos(model->camera.eyeX * PI / 180.0);
	}

	if (Etat_PieceNoire &&
		((sf::Time) Clock_ActionEvent.getElapsedTime()).asSeconds() - Clock_time_PieceNoire.asSeconds() > 10) {
		//std::cout << "tmps " << ((sf::Time) Clock_ActionEvent.getElapsedTime()).asSeconds() - Clock_time_PieceNoire.asSeconds() << std::endl;
		DesactivationPieceNoire();
	}

	// mur bleu
	int pos_x = (int) ceilf(model->camera.x);
	int pos_y = (int) ceilf(model->camera.y);
	ramassePiece(pos_x, pos_y);

	if (model->getMatrice()[pos_x][pos_y] == 1) {
		if (model->getMatrice()[(int) ceilf(tempx)][pos_y] == 1) {
			model->camera.y = tempy;
		} else if (model->getMatrice()[pos_x][(int) ceilf(tempy)] == 1) {
			model->camera.x = tempx;
		} else {
			model->camera.x = tempx;
			model->camera.y = tempy;
		}
	}

	// mur rouge
	int pos_x2 = (int) floor(model->camera.x);
	int pos_y2 = (int) floor(model->camera.y);
	ramassePiece(pos_x2, pos_y2);


	if (model->getMatrice()[pos_x2][pos_y2 - 1] == 1) {
		if (model->getMatrice()[(int) floor(tempx)][pos_y2 - 1] == 1) {
			model->camera.y = tempy;
		} else if (model->getMatrice()[pos_x2][(int) floor(tempy) - 1] == 1) {
			model->camera.x = tempx;
		} else {
			model->camera.x = tempx;
			model->camera.y = tempy;
		}
	}

	// mur vert
	int pos_x3 = (int) floor(model->camera.x);
	int pos_y3 = (int) ceilf(model->camera.y);
	ramassePiece(pos_x3, pos_y3);


	if (model->getMatrice()[pos_x3 - 1][pos_y3] == 1) {
		if (model->getMatrice()[(int) floor(tempx) - 1][pos_y3] == 1) {
			model->camera.y = tempy;
		} else if (model->getMatrice()[pos_x3 - 1][(int) ceilf(tempy)] == 1) {
			model->camera.x = tempx;
		} else {
			model->camera.x = tempx;
			model->camera.y = tempy;
		}
	}

	// mur jaune
	int pos_x4 = (int) ceilf(model->camera.x);
	int pos_y4 = (int) floor(model->camera.y);
	ramassePiece(pos_x4, pos_y4);

	if (model->getMatrice()[pos_x4][pos_y4] == 1) {
		if (model->getMatrice()[(int) ceilf(tempx)][pos_y4] == 1) {
			model->camera.y = tempy;
		} else if (model->getMatrice()[pos_x4][(int) floor(tempy)] == 1) {
			model->camera.x = tempx;
		} else {
			model->camera.x = tempx;
			model->camera.y = tempy;
		}
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
		ActivationPieceNoire();
	}
}

void Controller::ActivationPieceNoire() {
	Etat_PieceNoire = true;
	model->ChangeMusicPitch(1.5);
	Clock_time_PieceNoire = Clock_ActionEvent.getElapsedTime();    // /!\ Le chrono n'est jamais réinitialisé (pas besoin)
	model->setVitesseDep(model->getVitesseDep() + 8.0f);
	//std::cout << "Piece noire vitesse : " << model->getVitesseDep() << std::endl;
}

void Controller::DesactivationPieceNoire() {
	Etat_PieceNoire = false;
	model->ResetVitesseDep();
	model->ResetMusicPitch();
	//std::cout << "Desactivation piece noire vitesse : " << model->getVitesseDep() << std::endl;
}

int Controller::GetCompteur() {
	return compteur;
}

Controller::~Controller() {
	std::cout << "Destructeur de controleur" << std::endl;
	delete (Keyboard);
}
