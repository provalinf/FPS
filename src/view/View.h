//
// Created by Valentin on 28/10/2016.
//

#ifndef PACMAN_VIEW_H
#define PACMAN_VIEW_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include "../model/Model.h"
#include "../controller/Controller.h"
#include "../util/Gameobject.h"

const sf::String TITRE_FENETRE = "Pacman 3D";

class View {
private:
	Model *model;
	Controller *controller;
	Gameobject *gameobject;
	bool fullscreen;

	sf::RenderWindow window;

	sf::Clock Clock;
	sf::Text text_framerate;

public:
	View(Model *model, bool fullscreen);

	void CreationFenetre();

	void initialisation();

	void BouclePrincipale(sf::Image image);

	void displayFramerate(sf::RenderWindow &window, sf::Time clock);

	~View();
};


#endif //PACMAN_VIEW_H