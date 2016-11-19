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
	gameobject = new Gameobject(model);
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

    model->Loadmusic();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, (double) window.getSize().x / window.getSize().y, 1, 1000);
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);

	model->CreateMatrix(model->LoadImgMap("mapi_ori.png"));

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
	gluLookAt(model->camera.x, model->camera.y, model->camera.z,
			  model->camera.x - cos(-model->camera.eyeX * RAD),
			  model->camera.y + sin(-model->camera.eyeX * RAD),
			  model->camera.eyeZ, 0, 0, 1);

	//glTranslated(model->pos.x, model->pos.y, model->pos.z);

	//glBegin(GL_QUADS);

	/*...*/

//    glVertex3d(1,1,1);
//    glVertex3d(1,1,-1);
//    glVertex3d(-1,1,-1);
//    glVertex3d(-1,1,1);
    gameobject->CreateSkyBox(500,500,500,-64,-64,0);
	gameobject->CreateSol();
    gameobject->Ghost1();
    gameobject->Ghost2();
    gameobject->Ghost3();
    gameobject->Ghost4();
	gameobject->GenerateMap();


	glFlush();
}

void View::displayFramerate(sf::RenderWindow &window, sf::Time clock) {
	//double framerate = 1 / (clock.asMilliseconds() * 0.001);

	//std::ostringstream buff1;
    std::ostringstream buff2;
	//buff1 << framerate;
    buff2 << controller->GetCompteur();
    //text_framerate.setString("FPS : " + buff1.str());
    text_framerate.setString(buff2.str() + "/142");

	window.pushGLStates();          // Sauvegarde de l'état OpenGL
	window.draw(text_framerate);    // Affichage du texte
	window.popGLStates();           // Restauration de l'état OpenGL
}

View::~View() {
	std::cout << "Destructeur de vue" << std::endl;
	delete controller;
	delete gameobject;
}