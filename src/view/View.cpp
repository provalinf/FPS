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
	window.setFramerateLimit(70);
	window.setMouseCursorVisible(false);
	window.setKeyRepeatEnabled(false);
}

void View::Menu() {

    sf::Texture background;
    background.loadFromFile("Img/Menu/background.jpg");

    window.setMouseCursorVisible(true);

	BoutonMenu jouer = CreationBouton("Jouer",(window.getSize().x-150)/2, (window.getSize().y*1/5), 150, 40);
	BoutonMenu param = CreationBouton("Parametres",(window.getSize().x-150)/2, (window.getSize().y*2/5), 150, 40);
	BoutonMenu quitter = CreationBouton("Quitter",(window.getSize().x-150)/2, (window.getSize().y*3/5), 150, 40);

    while (window.isOpen()) {
        //std::cout << "Test" << std::endl;

        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
        }

        sf::RectangleShape rect (sf::Vector2f(window.getSize().x, window.getSize().y));
        rect.setTexture(&background);
        window.draw(rect);
        window.draw(jouer.background);
		window.draw(jouer.texte);

        window.draw(param.background);
        window.draw(param.texte);

        window.draw(quitter.background);
        window.draw(quitter.texte);

		if ((sf::Mouse::getPosition(window).x >= (window.getSize().x/2)-75)&&(sf::Mouse::getPosition(window).x <= (window.getSize().x/2)+75)&&
			(sf::Mouse::getPosition(window).y >= (window.getSize().y*1/5)&&(sf::Mouse::getPosition(window).y <= (window.getSize().y*1/5+40)))) {
			jouer.background.setFillColor(color.Green);
		}
		else{
			jouer.background.setFillColor(color.Red);
		}
		if ((sf::Mouse::getPosition(window).x >= (window.getSize().x/2)-75)&&(sf::Mouse::getPosition(window).x <= (window.getSize().x/2)+75)&&
			(sf::Mouse::getPosition(window).y >= (window.getSize().y*2/5)&&(sf::Mouse::getPosition(window).y <= (window.getSize().y*2/5+40)))) {
			param.background.setFillColor(color.Green);
		}
		else{
			param.background.setFillColor(color.Red);
		}
		if ((sf::Mouse::getPosition(window).x >= (window.getSize().x/2)-75)&&(sf::Mouse::getPosition(window).x <= (window.getSize().x/2)+75)&&
			(sf::Mouse::getPosition(window).y >= (window.getSize().y*3/5)&&(sf::Mouse::getPosition(window).y <= (window.getSize().y*3/5+40)))){
			quitter.background.setFillColor(color.Green);
		}
		else{
			quitter.background.setFillColor(color.Red);
		}

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if ((sf::Mouse::getPosition(window).x >= (window.getSize().x/2)-75)&&(sf::Mouse::getPosition(window).x <= (window.getSize().x/2)+75)&&
                    (sf::Mouse::getPosition(window).y >= (window.getSize().y*1/5)&&(sf::Mouse::getPosition(window).y <= (window.getSize().y*1/5+40)))){
                //std::cout<<"Tu as clique sur Jouer"<<std::endl;
                initialisation();
            }
			if ((sf::Mouse::getPosition(window).x >= (window.getSize().x/2)-75)&&(sf::Mouse::getPosition(window).x <= (window.getSize().x/2)+75)&&
				(sf::Mouse::getPosition(window).y >= (window.getSize().y*2/5)&&(sf::Mouse::getPosition(window).y <= (window.getSize().y*2/5+40)))){

				//std::cout<<"Tu as clique sur Parametres"<<std::endl;
			}
			if ((sf::Mouse::getPosition(window).x >= (window.getSize().x/2)-75)&&(sf::Mouse::getPosition(window).x <= (window.getSize().x/2)+75)&&
				(sf::Mouse::getPosition(window).y >= (window.getSize().y*3/5)&&(sf::Mouse::getPosition(window).y <= (window.getSize().y*3/5+40)))){
				//std::cout<<"Tu as clique sur Quitter"<<std::endl;
                window.close();
			}
        }

        window.setActive();
        window.display();
        window.clear();
    }
}

BoutonMenu View::CreationBouton(sf::String text, int x, int y, int longu, int larg) {
	BoutonMenu bouton;
	bouton.texte.setFont(model->getFont());
	bouton.texte.setCharacterSize(24); // in pixels, not points!
	bouton.texte.setString(text);
	bouton.texte.setOrigin((float) floor(bouton.texte.getLocalBounds().width / 2),
						   (float) floor(bouton.texte.getLocalBounds().height / 2));
	bouton.texte.setPosition(x + longu / 2, (y + larg / 2) - 5);
	bouton.x = x;
	bouton.y = y;
	bouton.longueur = longu;
	bouton.largeur = larg;
	bouton.background = sf::RectangleShape(sf::Vector2f(bouton.longueur, bouton.largeur));
	bouton.background.setFillColor(sf::Color(255, 0, 0, 150));
	bouton.background.setPosition(bouton.x, bouton.y);
	return bouton;
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

	map = new Map(model, "mappacman.png");
	skybox = new Skybox(model);

	for (int i = 0; i < 4; ++i) {
		ennemis[i] = new Enemy(model);
	}
	ennemis[0]->SetPosition(42.0f, 42.0f);
	ennemis[0]->EnemyLoadObj("Obj/Silent.obj", 1);
	ennemis[1]->SetPosition(42.0f, 42.0f);
	ennemis[1]->EnemyLoadObj("Obj/billy bike.obj", 2);
	ennemis[2]->SetPosition(42.0f, 42.0f);
	ennemis[2]->EnemyLoadObj("Obj/Dalek.obj", 3);
	ennemis[3]->SetPosition(42.0f, 42.0f);
	ennemis[3]->EnemyLoadObj("Obj/PortalTurretV2.obj", 4);
	//ennemis[7]->EnemyLoadObj("Obj/billy bike.obj", 2);
	//ennemis[7]->EnemyLoadObj("Obj/Dalek.obj", 3);
	//ennemis[7]->EnemyLoadObj("Obj/PortalTurretV2.obj", 4);


	while (window.isOpen()) {
		BouclePrincipale();

		window.setActive();

		displayMiniMap(window);
		displayNBPieceTempo(window);

		controller->ActionEvent();
		if (model->isDebug()) displayFramerate(window, Clock_framerate.restart());
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
	for (int i = 0; i < 4; ++i) {
		ennemis[i]->GenerateEnemy();
	}

	glFlush();
}

void View::displayMiniMap(sf::RenderWindow &window) {
	window.pushGLStates();          // Sauvegarde de l'état OpenGL

	float taille = 3;

	/*sf::RectangleShape rectangle(sf::Vector2f(model->getMap().x * taille, model->getMap().y * taille));
	rectangle.setPosition(window.getSize().x - (model->getMap().x * taille) - 10, 10);
	rectangle.setFillColor(sf::Color(0, 0, 0, 150));
	window.draw(rectangle);    // Affichage du texte*/

	int distance_affichage = 20;

	unsigned int x_mat = (unsigned int) (floor(model->camera.x - distance_affichage) >= 0 ? floor(
			model->camera.x - distance_affichage) : 0);
	unsigned int x_mat_fin = (unsigned int) (ceilf(model->camera.x + distance_affichage) <= model->getMap().x ? ceilf(
			model->camera.x + distance_affichage) : model->getMap().x);

	unsigned int y_mat = (unsigned int) (floor(model->camera.y - distance_affichage) >= 0 ? floor(
			model->camera.y - distance_affichage) : 0);
	unsigned int y_mat_fin = (unsigned int) (ceilf(model->camera.y + distance_affichage) <= model->getMap().y ? ceilf(
			model->camera.y + distance_affichage) : model->getMap().y);

	int x_t = 0;
	int y_t = 0;

	for (unsigned int x = x_mat; x < x_mat_fin; x++) {
		y_t = 0;
		for (unsigned int y = y_mat; y < y_mat_fin; y++) {
			if (model->getMatrice()[x][y] == 1) {
				TraceBlocMiniMap(x_t, y_t, 200, 200, 200, 100);
			} else if (model->getMatrice()[x][y] == 2) {
				TraceBlocMiniMap(x_t, y_t, 255, 255, 0);
			} else if (model->getMatrice()[x][y] == 3) {
				TraceBlocMiniMap(x_t, y_t, 255, 0, 0);
			} else if (model->getMatrice()[x][y] == 5) {
				TraceBlocMiniMap(x_t, y_t, 100, 100, 255);
			} else if (model->getMatrice()[x][y] == 6) {
				TraceBlocMiniMap(x_t, y_t, 150, 255, 0);
			} else {
				TraceBlocMiniMap(x_t, y_t, 0, 0, 0);
			}
			y_t++;
		}
		x_t++;
	}

	/*for (unsigned int x = 0; x < model->getMap().x; x++) {
		for (unsigned int y = 0; y < model->getMap().y; y++) {
			if (model->getMatrice()[x][y] == 1) {
				TraceBlocMiniMap(x, y, 10, 10, 10);

			} else if (model->getMatrice()[x][y] == 2) {
				TraceBlocMiniMap(x, y, 255, 255, 0);

			} else if (model->getMatrice()[x][y] == 3) {
				TraceBlocMiniMap(x, y, 255, 0, 0);
			}
		}
	}*/
	int pos_x_enemy;
	int pos_y_enemy;
	sf::RectangleShape rectangle;
	for (int i = 0; i < 4; ++i) {
		rectangle.setSize(sf::Vector2f(taille + 5, taille + 5));
		pos_x_enemy = (int) (window.getSize().x + (ennemis[i]->getPosition().fx * taille) - (model->getMap().x * taille) - 10);
		pos_y_enemy = (int) (10 + (ennemis[i]->getPosition().fy * taille));
		rectangle.setPosition(pos_x_enemy, pos_y_enemy);
		rectangle.setFillColor(sf::Color(0, 255, 0, 150));
		window.draw(rectangle);    // Affichage du texte
	}


	int radius = 8;
	sf::CircleShape cercle(radius);
	cercle.setPosition(window.getSize().x + model->getTailleMiniMap() - (20 * model->getTailleMiniMap()) - 10,
			10 + (model->getTailleMiniMap()*20));
	//cercle.setFillColor(sf::Color(0, 0, 0, 150));
	cercle.setOrigin(radius, radius);
	cercle.setRotation(model->camera.eyeX - 180);
	cercle.setTexture(&pacman);
	window.draw(cercle);    // Affichage du texte

	window.popGLStates();           // Restauration de l'état OpenGL
}

void View::TraceBlocMiniMap(int x, int y, sf::Uint8 R, sf::Uint8 V, sf::Uint8 B, sf::Uint8 A) {
	sf::RectangleShape bloc(sf::Vector2f(model->getTailleMiniMap(), model->getTailleMiniMap()));
	bloc.setPosition(
			window.getSize().x + (x * model->getTailleMiniMap()) - (40 * model->getTailleMiniMap()) - 10,
			10 + (y * model->getTailleMiniMap()));
	bloc.setFillColor(sf::Color(R, V, B, A));
	window.draw(bloc);
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
	if (model->isJeu_active()) {
		delete (skybox);
		delete (map);
		for (int i = 0; i < 4; ++i) {
			delete (ennemis[i]);
		}
	}

}