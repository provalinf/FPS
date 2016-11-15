//
// Created by Valentin on 28/10/2016.
//

#ifndef PACMAN_CONTROLLER_H
#define PACMAN_CONTROLLER_H

#include <SFML/Window/Event.hpp>
#include "../model/Model.h"
#include <SFML/Audio.hpp>

class Controller {
private:
	sf::RenderWindow &window;
	Model *model;
public:

	Controller(sf::RenderWindow &window, Model *model);

	~Controller();

    void MoveKeyPressed(sf::Event event, float myftime, sf::Sound sound);

    void ActionEvent(sf::Time time, sf::Sound sound);

    void ramassePiece(int x, int y, sf::Sound sound);
};


#endif //PACMAN_CONTROLLER_H
