#include <SFML/Window/Event.hpp>
#include <sstream>
#include <GL/glu.h>
#include <fstream>
#include <iostream>
#include <SFML/Audio/Music.hpp>
#include "View.h"


View::View(Model *model, bool fullscreen) {
	this->model = model;
	this->fullscreen = fullscreen;
	CreationFenetre();
	controller = new Controller(window, model);
	gameobject = new Gameobject();
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

//    glGenTextures(1, &m_id);
//    glBindTexture(GL_TEXTURE_2D, m_id);
//    glTexImage2D(GL_TEXTURE_2D, 0, formatInterne, imageSDL->w, imageSDL->h, 0, format, GL_UNSIGNED_BYTE, imageSDL->pixels);
//
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

void View::initialisation() {

	text_framerate.setFont(model->getFont());
	text_framerate.setCharacterSize(24); // in pixels, not points!

	sf::Music music;
	music.openFromFile("environmentmusic.wav");
	music.play();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, (double) (fullscreen ? model->getResolution().width : 800) /
					   (fullscreen ? model->getResolution().height : 600), 1, 1000);
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);


//    sf::Texture texture
//    texture.loadFromFile("texture2.jpg");
//    glEnable(GL_TEXTURE_2D);
//    sf::Texture::bind(&texture);

	while (window.isOpen()) {

		sf::Time myTime = Clock.getElapsedTime();

		controller->ActionEvent(myTime);

		sf::Image image;

		if (!image.loadFromFile("mapi.png")) {
			std::cout << "Failure to load map" << std::endl;
		}

		BouclePrincipale(image);

		window.setActive();
		if (model->isDebug()) {
			displayFramerate(window, Clock.restart());
		}

		window.display();
		window.clear();
	}
}

void View::BouclePrincipale(sf::Image image) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(model->camera.x, model->camera.y, model->camera.z, model->camera.eyeX, model->camera.eyeY,
			  model->camera.eyeZ, 0, 0, 1);
	glTranslated(model->pos.x, model->pos.y, model->pos.z);

	glBegin(GL_QUADS);

	/*...*/

//    glVertex3d(1,1,1);
//    glVertex3d(1,1,-1);
//    glVertex3d(-1,1,-1);
//    glVertex3d(-1,1,1);

	gameobject->CreateSol();
	gameobject->CreateMap(image);


	/*std::ifstream map = model->LoadMap("map.txt");
	if (map) {
		for (int j = 0; j < 11; j += 1) {
			std::string chaine;
			if (!map.eof()) {
				getline(map.ignore(0, '\n'), chaine);
				for (int i = 0; i < 11; i += 1) {
					if (chaine[i] == '1')gameobject->CreateCube(1, 1, 4, j, i, 0);
				}
			} else map.close();
		}
	} else { std::cout << "Impossible d'ouvrir la map /!\\" << std::endl; }*/

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

View::~View() {
	std::cout << "Destructeur de vue" << std::endl;
	delete controller;
	delete gameobject;
}