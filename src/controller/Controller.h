//
// Created by Valentin on 28/10/2016.
//

#ifndef PACMAN_CONTROLLER_H
#define PACMAN_CONTROLLER_H


class Controller {
private:
	sf::RenderWindow& window;
public:

	Controller(sf::RenderWindow &window);

	void ActionEvent();
};


#endif //PACMAN_CONTROLLER_H
