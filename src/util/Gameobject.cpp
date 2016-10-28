#include "Gameobject.h"
#include <SFML/OpenGL.hpp>


Gameobject::Gameobject() {
}

void Gameobject::CreateCube(float longueur, float largeur, float hauteur, int x, int y, int z) {

	glColor3ub(255, 0, 0); //face rouge
	glVertex3d(x + longueur, y + largeur, z + hauteur);
	glVertex3d(x + longueur, y + largeur, z + 0);
	glVertex3d(x + 0, y + largeur, z + 0);
	glVertex3d(x + 0, y + largeur, z + hauteur);

	glColor3ub(0, 255, 0); //face verte
	glVertex3d(x + longueur, y + 0, z + hauteur);
	glVertex3d(x + longueur, y + 0, z + 0);
	glVertex3d(x + longueur, y + largeur, z + 0);
	glVertex3d(x + longueur, y + largeur, z + hauteur);

	glColor3ub(0, 0, 255); //face bleue
	glVertex3d(x + 0, y + 0, z + hauteur);
	glVertex3d(x + 0, y + 0, z + 0);
	glVertex3d(x + longueur, y + 0, z + 0);
	glVertex3d(x + longueur, y + 0, z + hauteur);

	glColor3ub(255, 255, 0); //face jaune
	glVertex3d(x + 0, y + largeur, z + hauteur);
	glVertex3d(x + 0, y + largeur, z + 0);
	glVertex3d(x + 0, y + 0, z + 0);
	glVertex3d(x + 0, y + 0, z + hauteur);

	glColor3ub(0, 255, 255); //face cyan
	glVertex3d(x + longueur, y + largeur, z + 0);
	glVertex3d(x + longueur, y + 0, z + 0);
	glVertex3d(x + 0, y + 0, z + 0);
	glVertex3d(x + 0, y + largeur, z + 0);

	glColor3ub(255, 0, 255); //face magenta
	glVertex3d(x + longueur, y + 0, z + hauteur);
	glVertex3d(x + longueur, y + largeur, z + hauteur);
	glVertex3d(x + 0, y + largeur, z + hauteur);
	glVertex3d(x + 0, y + 0, z + hauteur);

	glColor3ub(255, 255, 0); //face jaune
	glVertex3d(x + 0, y + largeur, z + hauteur);
	glVertex3d(x + 0, y + largeur, z + 0);
	glVertex3d(x + 0, y + 0, z + 0);
	glVertex3d(x + 0, y + 0, z + hauteur);
}

void Gameobject::CreateFloor() {
	glColor3ub(0, 5, 60); //sol
	glVertex2d(100, 100);
	glVertex2d(100, 0);
	glVertex2d(0, 0);
	glVertex2d(0, 100);
}