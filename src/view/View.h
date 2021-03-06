//
// Created by Valentin on 28/10/2016.
//

#ifndef PACMAN_VIEW_H
#define PACMAN_VIEW_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include "../model/Model.h"
#include "../controller/Controller.h"
#include "../util/Skybox.h"
#include "../util/Map.h"
#include "../util/Enemy.h"

const sf::String TITRE_FENETRE = "Pacman 3D";

class View {
private:

	Model *model;
	Controller *controller;
	Map *map = NULL;
	Skybox *skybox = NULL;
	Enemy *ennemis[7];
	sf::Color color;

	bool fullscreen;

	sf::RenderWindow window;

	sf::Clock Clock_framerate;
	sf::Text text_framerate;
	sf::Text text_hud;


public:
	View(Model *model, bool fullscreen);

	~View();

	void CreationFenetre();

	void initialisation();

	void BouclePrincipale();

	void displayFramerate(sf::RenderWindow &window, sf::Time clock);

	void displayMiniMap();

	void TraceBlocMiniMap(float x, float y, float taille, sf::Uint8 R, sf::Uint8 V, sf::Uint8 B, sf::Uint8 A = 255, int coef = 0);

	void Menu();

	BoutonMenu CreationBouton(sf::String text, int x, int y, int longu, int larg);

	void HUD();
};


#endif //PACMAN_VIEW_H