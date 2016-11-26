//
// Created by Valentin on 20/11/2016.
//

#include <GL/gl.h>
#include <iostream>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "Map.h"

Map::Map(Model *model, sf::RenderWindow &window, sf::String nomMap) : Object(model), window(window) {
	model->CreateMatrix(model->LoadImgMap(nomMap));
	CreateTexture("Map", 7);	// Si qu'une texture, nommer l'image face1.jpg...
}

/*void Map::GenerateMap() {
	//LoadTexture(0);
	for (unsigned int x = 0; x < model->getMap().x; x++) {
		for (unsigned int y = 0; y < model->getMap().y; y++) {
			if (model->getMatrice()[x][y] == 1) {
				CreateMur(1, 1, 4, x, y, 0);
			} else if (model->getMatrice()[x][y] == 2) {
				pieces->CreateCoin(x, y);
			} else if (model->getMatrice()[x][y] == 3) {
				pieces->CreateSpeedCoin(x, y);
			}
		}
	}
}*/



/*void Map::GenerateMiniMap() {
	window.pushGLStates();          // Sauvegarde de l'état OpenGL

	for (unsigned int x = 0; x < model->getMap().x; x++) {
		for (unsigned int y = 0; y < model->getMap().y; y++) {
			if (model->getMatrice()[x][y] == 1) {
				sf::RectangleShape rectangle(sf::Vector2f(TailleMiniMap, TailleMiniMap));
				rectangle.setPosition(window.getSize().x+(x*TailleMiniMap)-(model->getMap().x*TailleMiniMap)-10, 10+(y*TailleMiniMap));
				rectangle.setFillColor(sf::Color(10, 10, 10));

				window.draw(rectangle);    // Affichage du texte

				//CreateMur(1, 1, 4, x, y, 0);
			} else if (model->getMatrice()[x][y] == 2) {
				sf::RectangleShape rectangle(sf::Vector2f(TailleMiniMap, TailleMiniMap));
				rectangle.setPosition(window.getSize().x+(x*TailleMiniMap)-(model->getMap().x*TailleMiniMap)-10, 10+(y*TailleMiniMap));
				rectangle.setFillColor(sf::Color(255, 255, 0));
				window.draw(rectangle);    // Affichage du texte
			} else if (model->getMatrice()[x][y] == 3) {
				//pieces->CreateSpeedCoin(x, y);
				sf::RectangleShape rectangle(sf::Vector2f(TailleMiniMap, TailleMiniMap));
				rectangle.setPosition(window.getSize().x+(x*TailleMiniMap)-(model->getMap().x*TailleMiniMap)-10, 10+(y*TailleMiniMap));
				rectangle.setFillColor(sf::Color(255, 0, 0));
				window.draw(rectangle);    // Affichage du texte
			} else if (model->getMatrice()[x][y] == 0) {
				sf::RectangleShape rectangle(sf::Vector2f(TailleMiniMap, TailleMiniMap));
				rectangle.setPosition(window.getSize().x+(x*TailleMiniMap)-(model->getMap().x*TailleMiniMap)-10, 10+(y*TailleMiniMap));
				rectangle.setFillColor(sf::Color(0, 0, 0, 150));
				window.draw(rectangle);    // Affichage du texte
			}
		}
	}

	for (int i = 0; i < 4; ++i) {
		sf::RectangleShape rectangle(sf::Vector2f(TailleMiniMap+5, TailleMiniMap+5));
		rectangle.setPosition(window.getSize().x+(ennemis[i]->getPosition().fx*TailleMiniMap)-(model->getMap().x*TailleMiniMap)-10, 10+(ennemis[i]->getPosition().fy*TailleMiniMap));
		rectangle.setFillColor(sf::Color(0, 255, 0, 150));
		window.draw(rectangle);    // Affichage du texte
	}


	int radius = 8;
	sf::CircleShape cercle(radius);
	cercle.setPosition(window.getSize().x+(model->camera.x*TailleMiniMap)-(model->getMap().x*TailleMiniMap)-10, 10+(model->camera.y*TailleMiniMap));
	//cercle.setFillColor(sf::Color(0, 0, 0, 150));
	cercle.setOrigin(radius, radius);
	cercle.setRotation(model->camera.eyeX-180);
	cercle.setTexture(&pacman);
	window.draw(cercle);    // Affichage du texte

	window.popGLStates();           // Restauration de l'état OpenGL
}*/

void Map::CreateBlocMiniMap(int x, int y, sf::Uint8 R, sf::Uint8 V, sf::Uint8 B, sf::Uint8 A) {
	sf::RectangleShape bloc(sf::Vector2f(model->getTailleMiniMap(), model->getTailleMiniMap()));
	bloc.setPosition(window.getSize().x+(x*model->getTailleMiniMap())-(model->getMap().x*model->getTailleMiniMap())-10, 10+(y*model->getTailleMiniMap()));
	bloc.setFillColor(sf::Color(R, V, B, A));
	window.draw(bloc);
}

void Map::CreateMur(float longueur, float largeur, float hauteur, float x, float y, float z) {

	LoadTexture(6);
	glBegin(GL_QUADS);
	//glColor3ub(255, 0, 0); //face rouge
	glTexCoord2d(0.0, 0.0);
	glVertex3d(x + longueur, y + largeur, z + hauteur);
	glTexCoord2d(0.0, 1.0);
	glVertex3d(x + longueur, y + largeur, z + 0);
	glTexCoord2d(1.0, 1.0);
	glVertex3d(x + 0, y + largeur, z + 0);
	glTexCoord2d(1.0, 0.0);
	glVertex3d(x + 0, y + largeur, z + hauteur);
	glEnd();

	LoadTexture(6);
	glBegin(GL_QUADS);
	//glColor3ub(0, 255, 0); //face verte
	glTexCoord2d(0.0, 0.0);
	glVertex3d(x + longueur, y + 0, z + hauteur);
	glTexCoord2d(0.0, 1.0);
	glVertex3d(x + longueur, y + 0, z + 0);
	glTexCoord2d(1.0, 1.0);
	glVertex3d(x + longueur, y + largeur, z + 0);
	glTexCoord2d(1.0, 0.0);
	glVertex3d(x + longueur, y + largeur, z + hauteur);
	glEnd();

	LoadTexture(6);
	glBegin(GL_QUADS);
	//glColor3ub(0, 0, 255); //face bleue
	glTexCoord2d(0.0, 0.0);
	glVertex3d(x + 0, y + 0, z + hauteur);
	glTexCoord2d(0.0, 1.0);
	glVertex3d(x + 0, y + 0, z + 0);
	glTexCoord2d(1.0, 1.0);
	glVertex3d(x + longueur, y + 0, z + 0);
	glTexCoord2d(1.0, 0.0);
	glVertex3d(x + longueur, y + 0, z + hauteur);
	glEnd();

	LoadTexture(6);
	glBegin(GL_QUADS);
	//glColor3ub(255, 255, 0); //face jaune
	glTexCoord2d(0.0, 0.0);
	glVertex3d(x + 0, y + largeur, z + hauteur);
	glTexCoord2d(0.0, 1.0);
	glVertex3d(x + 0, y + largeur, z + 0);
	glTexCoord2d(1.0, 1.0);
	glVertex3d(x + 0, y + 0, z + 0);
	glTexCoord2d(1.0, 0.0);
	glVertex3d(x + 0, y + 0, z + hauteur);
	glEnd();

	LoadTexture(6);
	glBegin(GL_QUADS);
	//glColor3ub(0, 255, 255); //face cyan	(Bas)
	glTexCoord2d(0.0, 0.0);
	glVertex3d(x + longueur, y + largeur, z + 0);
	glTexCoord2d(0.0, 1.0);
	glVertex3d(x + longueur, y + 0, z + 0);
	glTexCoord2d(1.0, 1.0);
	glVertex3d(x + 0, y + 0, z + 0);
	glTexCoord2d(1.0, 0.0);
	glVertex3d(x + 0, y + largeur, z + 0);
	glEnd();

	LoadTexture(6);
	glBegin(GL_QUADS);
	//glColor3ub(255, 0, 255); //face magenta	(Haut)
	glTexCoord2d(0.0, 0.0);
	glVertex3d(x + longueur, y + 0, z + hauteur);
	glTexCoord2d(0.0, 1.0);
	glVertex3d(x + longueur, y + largeur, z + hauteur);
	glTexCoord2d(1.0, 1.0);
	glVertex3d(x + 0, y + largeur, z + hauteur);
	glTexCoord2d(1.0, 0.0);
	glVertex3d(x + 0, y + 0, z + hauteur);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

Map::~Map() {
	std::cout << "Destructeur de map" << std::endl;
}

