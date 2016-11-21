#include <SFML/Window/Event.hpp>
#include <sstream>
#include <GL/glu.h>
#include <fstream>
#include <iostream>
#include <SFML/Audio.hpp>
#include "View.h"

const double RAD = atan(1) * 4 / 180; // atan(1)*4 = PI

View::View(Model *model, bool fullscreen) {
	this->model = model;
	this->fullscreen = fullscreen;
	CreationFenetre();
	controller = new Controller(window, model);
}

void View::CreationFenetre() {
	sf::ContextSettings Settings;
	Settings.depthBits = 32;        // Request a 24-bit depth buffer
	Settings.stencilBits = 10;      // Request a 8 bits stencil buffer
	Settings.antialiasingLevel = 4; // Request 2 levels of antialiasing
	window.create(sf::VideoMode((fullscreen ? model->getResolution().width : 800),
								(fullscreen ? model->getResolution().height : 600),
								32), TITRE_FENETRE, (fullscreen ? sf::Style::Fullscreen : sf::Style::Close), Settings
	);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	window.setMouseCursorVisible(false);
}

void View::initialisation() {

	text_framerate.setFont(model->getFont());
	text_framerate.setCharacterSize(24); // in pixels, not points!

	// -- TEMPO
	text_nbpiece.setFont(model->getFont());
	text_nbpiece.setCharacterSize(24); // in pixels, not points!
	text_nbpiece.move(0, 20);
	// -- TEMPO

	model->Loadmusic();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, (double) window.getSize().x / window.getSize().y, 1, 1000);
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);


	map = new Map(model, "mapi_ori.png");
	skybox = new Skybox(model);

	for (int i = 0; i < 4; ++i) {
		ennemis[i] = new Enemy(model);
	}
	ennemis[0]->SetPosition(4, 2);
	ennemis[1]->SetPosition(45, 9);
	ennemis[2]->SetPosition(25, 26);
	ennemis[3]->SetPosition(18, 2);


	while (window.isOpen()) {
		sf::Time myTime = Clock.getElapsedTime();

		controller->ActionEvent(myTime);
		BouclePrincipale();

		window.setActive();
		if (model->isDebug()) {
			displayFramerate(window, Clock.restart());
		}
		displayNBPieceTempo(window);

		window.display();
		window.clear();
	}
}

void View::BouclePrincipale() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(model->camera.x, model->camera.y, model->camera.z,
			  model->camera.x - cos(-model->camera.eyeX * RAD),
			  model->camera.y + sin(-model->camera.eyeX * RAD),
			  model->camera.eyeZ, 0, 0, 1);

	map->GenerateMap();
	skybox->GenerateSkyBox();

	/*for (int i = 0; i < 4; ++i) {
		ennemis[i]->GenerateEnemy();
	}*/

	// -- TEMPO débug ennemi
	ennemis[0]->GenerateEnemy();
	// -- TEMPO débug ennemi

	glFlush();
}

void View::displayFramerate(sf::RenderWindow &window, sf::Time clock) {
	double framerate = 1 / (clock.asMilliseconds() * 0.001);

	std::ostringstream buff1;
	buff1 << framerate;
	text_framerate.setString("FPS : " + buff1.str());

	window.pushGLStates();          // Sauvegarde de l'état OpenGL
	window.draw(text_framerate);    // Affichage du texte
	window.popGLStates();           // Restauration de l'état OpenGL
}

void View::displayNBPieceTempo(sf::RenderWindow &window) {
	std::ostringstream buff2;
	buff2 << controller->GetCompteur();
	text_nbpiece.setString(buff2.str() + "/142");

	window.pushGLStates();          // Sauvegarde de l'état OpenGL
	window.draw(text_nbpiece);    // Affichage du texte
	window.popGLStates();           // Restauration de l'état OpenGL
}

View::~View() {
	std::cout << "Destructeur de vue" << std::endl;
	delete (controller);
	delete (skybox);
	delete (map);
	for (int i = 0; i < 4; ++i) {
		delete (ennemis[i]);
	}
}