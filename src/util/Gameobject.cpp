#include <GL/gl.h>
#include <iostream>
#include <SFML/Graphics/Texture.hpp>
#include "Gameobject.h"


Gameobject::Gameobject() {

}

void Gameobject::CreateCube(float longueur, float largeur, float hauteur, int x, int y, int z) {


	glColor3ub(255, 0, 0); //face rouge
    glTexCoord2i(1, 0); glVertex3d(x + longueur, y + largeur, z + hauteur);
    glTexCoord2i(1, 0); glVertex3d(x + longueur, y + largeur, z + 0);
    glTexCoord2i(1, 0); glVertex3d(x + 0, y + largeur, z + 0);
    glTexCoord2i(1, 0); glVertex3d(x + 0, y + largeur, z + hauteur);

	glColor3ub(0, 255, 0); //face verte
    glTexCoord2i(1, 0); glVertex3d(x + longueur, y + 0, z + hauteur);
    glTexCoord2i(1, 0); glVertex3d(x + longueur, y + 0, z + 0);
    glTexCoord2i(1, 0); glVertex3d(x + longueur, y + largeur, z + 0);
    glTexCoord2i(1, 0); glVertex3d(x + longueur, y + largeur, z + hauteur);

	glColor3ub(0, 0, 255); //face bleue
    glTexCoord2i(1, 0); glVertex3d(x + 0, y + 0, z + hauteur);
    glTexCoord2i(1, 0); glVertex3d(x + 0, y + 0, z + 0);
    glTexCoord2i(1, 0); glVertex3d(x + longueur, y + 0, z + 0);
    glTexCoord2i(1, 0); glVertex3d(x + longueur, y + 0, z + hauteur);

	glColor3ub(255, 255, 0); //face jaune
    glTexCoord2i(1, 0); glVertex3d(x + 0, y + largeur, z + hauteur);
    glTexCoord2i(1, 0); glVertex3d(x + 0, y + largeur, z + 0);
    glTexCoord2i(1, 0); glVertex3d(x + 0, y + 0, z + 0);
    glTexCoord2i(1, 0); glVertex3d(x + 0, y + 0, z + hauteur);

	glColor3ub(0, 255, 255); //face cyan
    glTexCoord2i(1, 0); glVertex3d(x + longueur, y + largeur, z + 0);
    glTexCoord2i(1, 0); glVertex3d(x + longueur, y + 0, z + 0);
    glTexCoord2i(1, 0); glVertex3d(x + 0, y + 0, z + 0);
    glTexCoord2i(1, 0); glVertex3d(x + 0, y + largeur, z + 0);

	glColor3ub(255, 0, 255); //face magenta
    glTexCoord2i(1, 0); glVertex3d(x + longueur, y + 0, z + hauteur);
    glTexCoord2i(1, 0); glVertex3d(x + longueur, y + largeur, z + hauteur);
    glTexCoord2i(1, 0); glVertex3d(x + 0, y + largeur, z + hauteur);
    glTexCoord2i(1, 0); glVertex3d(x + 0, y + 0, z + hauteur);

	glColor3ub(255, 255, 0); //face jaune
    glTexCoord2i(1, 0); glVertex3d(x + 0, y + largeur, z + hauteur);
    glTexCoord2i(1, 0); glVertex3d(x + 0, y + largeur, z + 0);
    glTexCoord2i(1, 0); glVertex3d(x + 0, y + 0, z + 0);
    glTexCoord2i(1, 0); glVertex3d(x + 0, y + 0, z + hauteur);
}

void Gameobject::CreateSol() {
	glColor3ub(0, 5, 60); //sol
    glTexCoord2i(0, 1); glVertex2d(128, 128);
    glTexCoord2i(1, 0); glVertex2d(128, 0);
    glTexCoord2i(1, 1); glVertex2d(0, 0);
    glTexCoord2i(0, 0); glVertex2d(0, 128);
}

Gameobject::~Gameobject(){};