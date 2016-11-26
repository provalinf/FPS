#include <SFML/Window/Event.hpp>
#include <sstream>
#include <GL/glu.h>
#include <fstream>
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "View.h"

const double RAD = atan(1) * 4 / 180; // atan(1)*4 = PI

View::View(Model *model, bool fullscreen) {
	this->model = model;
	this->fullscreen = fullscreen;
	CreationFenetre();
	controller = new Controller(window, model);


    pacman.loadFromFile("Img/Pacman-Logo.png");
}

void View::CreationFenetre() {
	sf::ContextSettings Settings;
	Settings.depthBits = 24;        // Request a 24-bit depth buffer
	Settings.stencilBits = 8;      // Request a 8 bits stencil buffer
	Settings.antialiasingLevel = 6; // Request 2 levels of antialiasing
	window.create(sf::VideoMode((fullscreen ? model->getResolution().width : 800),
								(fullscreen ? model->getResolution().height : 600),
								32), TITRE_FENETRE, (fullscreen ? sf::Style::Fullscreen : sf::Style::Close), Settings
	);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	window.setMouseCursorVisible(false);
	window.setKeyRepeatEnabled(false);
}

void View::initialisation() {

	text_framerate.setFont(model->getFont());
	text_framerate.setCharacterSize(24); // in pixels, not points!

	// -- TEMPO
	text_nbpiece.setFont(model->getFont());
	text_nbpiece.setCharacterSize(24); // in pixels, not points!
	text_nbpiece.move(0, 20);
	// -- TEMPO

	model->LanceMusic();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, (double) window.getSize().x / window.getSize().y, 1, 1000);
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);

	map = new Map(model, window, "map1.png");
	skybox = new Skybox(model);
	pieces = new Piece(model, window);

	for (int i = 0; i < 4; ++i) {
		ennemis[i] = new Enemy(model);
	}
	ennemis[0]->SetPosition(4.0f, 2.0f);
	ennemis[1]->SetPosition(45.0f, 9.0f);
	ennemis[2]->SetPosition(25.0f, 26.0f);
	ennemis[3]->SetPosition(18.0f, 2.0f);


	while (window.isOpen()) {
		sf::Time myTime = Clock.getElapsedTime();

		controller->ActionEvent(myTime);
		BouclePrincipale();

		window.setActive();
		if (model->isDebug()) {
			displayFramerate(window, Clock.restart());
		}
        //displayMiniMap(window);
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

	//map->GenerateMap();
	//map->GenerateMiniMap();
	GenerateMapAndMiniMap();
	//skybox->GenerateSkyBox();

	for (int i = 0; i < 4; ++i) {
		ennemis[i]->GenerateEnemy();
	}

	glFlush();
}

void View::GenerateMapAndMiniMap() {

	for (unsigned int x = 0; x < model->getMap().x; x++) {
		for (unsigned int y = 0; y < model->getMap().y; y++) {
			if (model->getMatrice()[x][y] == 1) {
				map->CreateMur(1, 1, 4, x, y, 0);
				//map->CreateBlocMiniMap(x, y, 10, 10, 10);
			} else if (model->getMatrice()[x][y] == 2) {
				//pieces->CreateCoin(x, y);
				//pieces->CreatePieceMiniMap(x, y, 255, 255, 0);
			} else if (model->getMatrice()[x][y] == 3) {
				//pieces->CreateSpeedCoin(x, y);
				//pieces->CreatePieceMiniMap(x, y, 255, 0, 0);
			} else if (model->getMatrice()[x][y] == 0) {	// Background minimap
				//map->CreateBlocMiniMap(x, y, 0, 0, 0, 150);
			}
		}
	window.pushGLStates();          // Sauvegarde de l'état OpenGL

		for (unsigned int y = 0; y < model->getMap().y; y++) {
			if (model->getMatrice()[x][y] == 1) {
				map->CreateBlocMiniMap(x, y, 10, 10, 10);
			} else if (model->getMatrice()[x][y] == 2) {
				//pieces->CreatePieceMiniMap(x, y, 255, 255, 0);
			} else if (model->getMatrice()[x][y] == 3) {
				//pieces->CreatePieceMiniMap(x, y, 255, 0, 0);
			} else if (model->getMatrice()[x][y] == 0) {	// Background minimap
				map->CreateBlocMiniMap(x, y, 0, 0, 0, 150);
			}
		}
			window.popGLStates();           // Restauration de l'état OpenGL

	}

}


void View::displayFramerate(sf::RenderWindow &window, sf::Time clock) {
	double framerate = 1 / (clock.asMilliseconds() * 0.001);
	text_framerate.setString("FPS : " + model->toString(framerate));

	window.pushGLStates();          // Sauvegarde de l'état OpenGL
	window.draw(text_framerate);    // Affichage du texte
	window.popGLStates();           // Restauration de l'état OpenGL
}

void View::displayNBPieceTempo(sf::RenderWindow &window) {
	text_nbpiece.setString(
			model->toString(controller->GetCompteur()) + "/" + model->toString(model->getNombreTotalPiece()));

	window.pushGLStates();          // Sauvegarde de l'état OpenGL
	window.draw(text_nbpiece);    // Affichage du texte
	window.popGLStates();           // Restauration de l'état OpenGL
}

View::~View() {
	std::cout << "Destructeur de vue" << std::endl;
	delete (controller);
	delete (skybox);
	delete (map);
	delete (pieces);
	for (int i = 0; i < 4; ++i) {
		delete (ennemis[i]);
	}
}