#include <SFML/Window/Event.hpp>
#include <sstream>
#include <GL/glu.h>
#include <fstream>
#include <iostream>
#include "View.h"


View::View(Model *model) {
	this->model = model;
	CreationFenetre();
	controller = new Controller(window, model);
	gameobject = new Gameobject();
}

void View::CreationFenetre() {
	sf::ContextSettings Settings;
	Settings.depthBits = 32;        // Request a 24-bit depth buffer
	Settings.stencilBits = 10;      // Request a 8 bits stencil buffer
	Settings.antialiasingLevel = 4; // Request 2 levels of antialiasing
	window.create(sf::VideoMode(640, 480, 32), TITRE_FENETRE, sf::Style::Close, Settings);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
}

void View::initialisation() {
	text_framerate.setFont(model->getFont());
	text_framerate.setCharacterSize(24); // in pixels, not points!

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, (double) 640 / 480, 1, 1000);
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);

	while (window.isOpen()) {
		sf::Time myTime = Clock.getElapsedTime();

		controller->ActionEvent(myTime);
		BouclePrincipale();

		window.setActive();
		if (model->isDebug()) {
			displayFramerate(window, Clock.restart());
		}
		window.display();
		window.clear();
	}
}

void View::BouclePrincipale() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(model->camera.x, model->camera.y, model->camera.z, model->camera.eyeX, model->camera.eyeY,
			  model->camera.eyeZ, 0, 0, 1);
	glTranslated(model->pos.x, model->pos.y, model->pos.z);

	glBegin(GL_QUADS);

	/*...*/
	gameobject->CreateSol();

	std::ifstream map = model->LoadMap("map.txt");
	if (map) {
		for (int j = 0; j < 11; j += 1) {
			std::string chaine;
			if (!map.eof()) {
				getline(map.ignore(0, '\n'), chaine);
				for (int i = 0; i < 11; i += 1) {
					if (chaine[i] == '1')gameobject->CreateCube(1, 1, 1, j, i, 0);
				}
			} else map.close();
		}
	} else { std::cout << "Impossible d'ouvrir la map /!\\" << std::endl; }


	glEnd();
	glFlush();
}

void View::displayFramerate(sf::RenderWindow &window, sf::Time clock) {
	double framerate = 1 / (clock.asMilliseconds() * 0.001);

	std::ostringstream buff;
	buff << framerate;
	text_framerate.setString("FPS : " + buff.str());

	window.pushGLStates();          // Sauvegarde de l'état OpenGL
	window.draw(text_framerate);    // Affichage du texte
	window.popGLStates();           // Restauration de l'état OpenGL
}