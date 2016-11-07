//
// Created by Valentin on 28/10/2016.
//

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include "Controller.h"

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
			model->camera.x = sf::Mouse::getPosition(window).x * 0.3;
		}

		MoveKeyPressed(event, time.asSeconds());
	}
	MoveKeyPressed(event,
				   time.asSeconds());    // Évite/(Réduit) le temps d'attente système pour la répétition d'une touche (Temporaire, ne fonctionne que sur les architectures de faible puissance)

}

void Controller::MoveKeyPressed(sf::Event event, float myftime) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Left) model->pos.y += model->getVitesseDep() * myftime;/** ellapsed_time*/;
		if (event.key.code == sf::Keyboard::Right) model->pos.y -= model->getVitesseDep() * myftime/** ellapsed_time*/;
		if (event.key.code == sf::Keyboard::Up) model->camera.x -= model->getVitesseDep() * myftime/** ellapsed_time*/;
		if (event.key.code == sf::Keyboard::Down)
			model->camera.x += model->getVitesseDep() * myftime/** ellapsed_time*/;
	}
}

Controller::~Controller() {
	std::cout << "Destructeur de controlleur" << std::endl;
};
