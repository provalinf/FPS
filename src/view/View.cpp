#include <SFML/Window/Event.hpp>
#include "View.h"

View::View(Model *model) {
	this->model = model;
	CreationFenetre();
	controller = new Controller(window);
}

void View::initialisation() {
	while (window.isOpen()) {
		controller->ActionEvent();
		BouclePrincipale();
	}
}

void View::CreationFenetre() {
	sf::ContextSettings Settings;
	Settings.depthBits = 32; // Request a 24-bit depth buffer
	Settings.stencilBits = 10;  // Request a 8 bits stencil buffer
	Settings.antialiasingLevel = 4;  // Request 2 levels of antialiasing
	window.create(sf::VideoMode(640, 480, 32), TITRE_FENETRE, sf::Style::Close, Settings);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
}

void View::BouclePrincipale() {


}