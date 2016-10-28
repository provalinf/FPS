//
// Created by Valentin on 28/10/2016.
//

#ifndef PACMAN_VIEW_H
#define PACMAN_VIEW_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "../model/Model.h"
#include "../controller/Controller.h"

const sf::String TITRE_FENETRE = "Pacman 3D";

class View {
private:
	Model *model;
	Controller *controller;
	sf::RenderWindow window;

public:
	View(Model *model);

	void initialisation();

	void BouclePrincipale();

	void CreationFenetre();
};


#endif //PACMAN_VIEW_H