//
// Created by Valentin on 28/10/2016.
//

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include "Controller.h"

const double PI = atan(1) * 4;

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
	MoveKeyPressed(event,
				   time.asSeconds());    // Évite/(Réduit) le temps d'attente système pour la répétition d'une touche (Temporaire, ne fonctionne que sur les architectures de faible puissance)

}

void Controller::MoveKeyPressed(sf::Event event, float myftime) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Left) {
			model->camera.y += model->getVitesseDep() * myftime * sin(model->camera.eyeX * PI / 90.0);
			model->camera.x += model->getVitesseDep() * myftime * cos(model->camera.eyeX * PI / 90.0);
			//model->pos.y += model->getVitesseDep() * myftime;
		}/** ellapsed_time*/;
		if (event.key.code == sf::Keyboard::Right) {
			model->camera.y -= model->getVitesseDep() * myftime * sin(model->camera.eyeX * PI / 90.0);
			model->camera.x -= model->getVitesseDep() * myftime * cos(model->camera.eyeX * PI / 90.0);
			//model->pos.y -= model->getVitesseDep() * myftime/** ellapsed_time*/;
		}
		if (event.key.code == sf::Keyboard::Up) {
			//model->camera.x -= model->getVitesseDep() * myftime/** ellapsed_time*/;
			model->camera.y -= model->getVitesseDep() * myftime * sin(model->camera.eyeX * PI / 180.0);
			model->camera.x -= model->getVitesseDep() * myftime * cos(model->camera.eyeX * PI / 180.0);
		}

		if (event.key.code == sf::Keyboard::Down) {
			//model->camera.x += model->getVitesseDep() * myftime/** ellapsed_time*/;
			model->camera.y += model->getVitesseDep() * myftime * sin(model->camera.eyeX * PI / 180.0);
			model->camera.x += model->getVitesseDep() * myftime * cos(model->camera.eyeX * PI / 180.0);
		}
	}
}

Controller::~Controller() {
	std::cout << "Destructeur de controlleur" << std::endl;
};
