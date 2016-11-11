#include <GL/gl.h>
#include <iostream>
#include <SFML/Graphics/Texture.hpp>
#include <GL/glu.h>
#include "Gameobject.h"


Gameobject::Gameobject() {}

void Gameobject::CreateCoin(double x, double y){

    glColor3ub(255,0,0);
    GLUquadricObj* quadra;
    quadra = gluNewQuadric();
    glPushMatrix();
    glTranslatef(x,y,CoinHeight);
    gluSphere(quadra,0.1,5,5);
    glPopMatrix();
    gluDeleteQuadric(quadra);
}

void Gameobject::CreateCube(float longueur, float largeur, float hauteur, int x, int y, int z) {

    glBegin(GL_QUADS);
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

    glEnd();
}

void Gameobject::CreateSol(){

    glBegin(GL_QUADS);
    glColor3ub(0, 5, 60); //sol
    glTexCoord2i(0, 1); glVertex2d(128, 128);
    glTexCoord2i(1, 0); glVertex2d(128, 0);
    glTexCoord2i(1, 1); glVertex2d(0, 0);
    glTexCoord2i(0, 0); glVertex2d(0, 128);
    glEnd();
}

void Gameobject::CreateMatrix(sf::Image image ,int *tab){

    for(int y = 0; y < 4096; y+=64) {
        for (int x = 0; x < 64; x++) {
            if(image.getPixel(x,y/64) == color.Black){
                tab[x+y]=1;
            }
            else if (image.getPixel(x,y/64) == color.White){
                tab[x+y] = 0;
            }
            else if (image.getPixel(x,y/64) == color.Red){
                tab[x+y] = 2;
            }
        }
    }
}

void Gameobject::CreateMap(int *pointeurmap){

    for(int y = 0; y < 4096; y+=64) {
        for (int x = 0; x < 64; x++) {
            if (pointeurmap[x+y] == 1) {
                CreateCube(1, 1, 4, x, y/64, 0);
            }
            else if (pointeurmap[x+y] == 2) {
                CreateCoin(x,y/64);
                //CreateCube(0.3,0.3,0.3,x,y,1);
            }

        }
    }
}

    /*for(int y = 0; y < 64; y++) {
        for (int x = 0; x < 64; x++) {
            if (image.getPixel(x,y) == color.Black) {
                CreateCube(1, 1, 4, x, y, 0);
            }
            else if (image.getPixel(x,y) == color.Red) {
                CreateCoin(x,y);
                //CreateCube(0.3,0.3,0.3,x,y,1);
            }

            }
        }
    }*/
Gameobject::~Gameobject(){
	std::cout << "Destructeur de gameobject" << std::endl;
};