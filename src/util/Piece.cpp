//
// Created by Valentin on 20/11/2016.
//

#include <GL/glu.h>
#include <iostream>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Piece.h"

Piece::Piece(Model *model, sf::RenderWindow &window) : Object(model), window(window) {}

void Piece::CreateCoin(int x, int y) {
	glColor3ub(157, 0, 157);
	GLUquadricObj *quadra = gluNewQuadric();
	glPushMatrix();
	glTranslatef(x, y, model->getHauteurPiece());
	gluSphere(quadra, 0.3, 10, 10);
	glPopMatrix();
	gluDeleteQuadric(quadra);
}

void Piece::CreateSpeedCoin(int x, int y) {
	glColor3ub(0, 0, 0);
	GLUquadricObj *quadra = gluNewQuadric();
	glPushMatrix();
	glTranslatef(x, y, model->getHauteurPiece());
	gluSphere(quadra, 0.5, 10, 10);
	glPopMatrix();
	gluDeleteQuadric(quadra);
}

void Piece::CreatePieceMiniMap(int x, int y, sf::Uint8 R, sf::Uint8 V, sf::Uint8 B, sf::Uint8 A) {
	sf::RectangleShape bloc(sf::Vector2f(model->getTailleMiniMap(), model->getTailleMiniMap()));
	bloc.setPosition(window.getSize().x+(x*model->getTailleMiniMap())-(model->getMap().x*model->getTailleMiniMap())-10, 10+(y*model->getTailleMiniMap()));
	bloc.setFillColor(sf::Color(R, V, B, A));
	window.draw(bloc);
}

Piece::~Piece() {
	std::cout << "Destructeur de piece" << std::endl;
}
