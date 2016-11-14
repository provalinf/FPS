//
// Created by Valentin on 28/10/2016.
//

#ifndef PACMAN_CONTROLLER_H
#define PACMAN_CONTROLLER_H

#include <SFML/Window/Event.hpp>
#include "../model/Model.h"

class Controller {
private:
	sf::RenderWindow &window;
	Model *model;
public:

	Controller(sf::RenderWindow &window, Model *model);

	void ActionEvent(sf::Time time1, int *pointeurmap);

	void MoveKeyPressed(sf::Event event, float d, int *pointeurmap);

	void TestWall(int *pointeurmap);

	~Controller();
};


#endif //PACMAN_CONTROLLER_H
