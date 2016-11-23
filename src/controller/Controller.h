//
// Created by Valentin on 28/10/2016.
//

#ifndef PACMAN_CONTROLLER_H
#define PACMAN_CONTROLLER_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Text.hpp>
#include "../model/Model.h"

class Controller {
private:
	sf::RenderWindow &window;
	Model *model;

	sf::Clock Clock_ActionEvent;
	sf::Time Clock_time_PieceNoire;
	bool Etat_PieceNoire = false;

	int compteur = 0;

public:

	Controller(sf::RenderWindow &window, Model *model);

	~Controller();

	void ActionEvent(sf::Time time);

	void MoveKeyPressed(sf::Event event, sf::Time myftime);

	void ramassePiece(int x, int y);

	int GetCompteur();

	void ActivationPieceNoire();

	void DesactivationPieceNoire();

	bool *Keyboard = new bool[4]{false};

	void MoveKeyboard(sf::Event event);
};


#endif //PACMAN_CONTROLLER_H
