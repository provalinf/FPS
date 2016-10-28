#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include <gl/glu.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include "util/Gameobject.h"


void Dessiner();

float angleZ = 0.f;
float angleY = 0.f;
double centerX = 0;
gameobject obj;
sf::Font font;
sf::Text text_framerate;

void displayFramerate(sf::RenderWindow &window, sf::Time clock);

int main(int, char const **) {

	// Create the main window
	sf::ContextSettings Settings;
	Settings.depthBits = 32; // Request a 24-bit depth buffer
	Settings.stencilBits = 10;  // Request a 8 bits stencil buffer
	Settings.antialiasingLevel = 4;  // Request 2 levels of antialiasing
	sf::RenderWindow window(sf::VideoMode(640, 480, 32), "SFML OpenGL", sf::Style::Close, Settings);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	// Chargement de la font pour texte
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "Erreur chargement font" << std::endl;
		return -1;
	}

	text_framerate.setFont(font);
	text_framerate.setCharacterSize(24); // in pixels, not points!


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, (double) 640 / 480, 1, 1000);
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);

	sf::Clock Clock;

	const float Speed = 60.f;

	// Start the game loop
	while (window.isOpen()) {

		sf::Time myTime = Clock.getElapsedTime();
		float myftime = myTime.asSeconds();

		// Process events
		sf::Event event;
		while (window.pollEvent(event)) {
			// Close window: exit
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			// Escape pressed: exit
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				window.close();
			}

			//sf::Vector2i localPosition = sf::Mouse::getPosition(window);
			//if (SDL_MOUSEMOTION == event.type)centerX = event.motion.xrel*0.1;
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))centerX = sf::Mouse::getPosition(window).x * 0.3;

			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Left) angleZ += Speed * myftime;/** ellapsed_time*/;
				if (event.key.code == sf::Keyboard::Right)angleZ -= Speed * myftime/** ellapsed_time*/;
				if (event.key.code == sf::Keyboard::Up)angleY -= Speed * myftime/** ellapsed_time*/;
				if (event.key.code == sf::Keyboard::Down)angleY += Speed * myftime/** ellapsed_time*/;
			}
		}
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Left) angleZ += Speed * myftime;/** ellapsed_time*/;
			if (event.key.code == sf::Keyboard::Right)angleZ -= Speed * myftime/** ellapsed_time*/;
			if (event.key.code == sf::Keyboard::Up)angleY -= Speed * myftime/** ellapsed_time*/;
			if (event.key.code == sf::Keyboard::Down)angleY += Speed * myftime/** ellapsed_time*/;
		}

		window.setActive();

		Dessiner();
		displayFramerate(window, Clock.restart());

		// Update the window
		window.display();
		window.clear();

	}

	return EXIT_SUCCESS;
}

void displayFramerate(sf::RenderWindow &window, sf::Time clock) {
	double framerate = 1 / (clock.asMilliseconds() * 0.001);

	std::ostringstream buff;
	buff << framerate;
	text_framerate.setString("FPS : " + buff.str());

	window.pushGLStates();          // Sauvegarde de l'�tat OpenGL
	window.draw(text_framerate);    // Affichage du texte
	window.popGLStates();           // Restauration de l'�tat OpenGL
}

void Dessiner() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(angleY, 0, 8, 0, centerX, 0, 0, 0, 1);
	glTranslated(0, angleZ, 0);

	glBegin(GL_QUADS);

	obj.CreateFloor();

	std::ifstream fichier("map.txt", std::ios::in);
	if (fichier) {
		for (int j = 0; j < 11; j += 1) {
			std::string chaine;
			if (!fichier.eof()) {
				getline(fichier.ignore(0, '\n'), chaine);
				for (int i = 0; i < 11; i += 1) {
					if (chaine[i] == '1')obj.CreateCube(1, 1, 1, j, i, 0);
				}
			} else fichier.close();
		}
	} else { std::cout << "Pas de fichier" << std::endl; }

	glEnd();
	glFlush();
}
