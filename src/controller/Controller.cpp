//
// Created by Valentin on 28/10/2016.
//

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Controller.h"

Controller::Controller(sf::RenderWindow &window) : window(window) {

}

void Controller::ActionEvent() {
	sf::Event event;
	while (window.pollEvent(event)) {
		// évènement "fermeture demandée" : on ferme la fenêtre
		if (event.type == sf::Event::Closed)
			window.close();
	}
}


