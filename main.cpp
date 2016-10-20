#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include <gl/glu.h>
#include <iostream>
#include <sstream>

void Dessiner();

float angleZ = 0.f;
float angleY = 0.f;
double centerX = 0;

sf::Font font;
sf::Text text_framerate;

void displayFramerate(sf::RenderWindow& window, sf::Time clock) ;

int main(int, char const**)
{
	// Create the main window
	sf::ContextSettings Settings;
	Settings.depthBits = 32; // Request a 24-bit depth buffer
	Settings.stencilBits = 10;  // Request a 8 bits stencil buffer
	Settings.antialiasingLevel = 4;  // Request 2 levels of antialiasing
	sf::RenderWindow window(sf::VideoMode(640, 480, 32), "SFML OpenGL", sf::Style::Close, Settings);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	// Chargement de la font pour texte
	if (!font.loadFromFile("arial.ttf"))
	{
		std::cout << "Erreur chargement font" << std::endl;
		return -1;
	}

	text_framerate.setFont(font);
	text_framerate.setCharacterSize(24); // in pixels, not points!


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, (double)640 / 480, 1, 1000);
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);

	sf::Clock Clock;

	const float Speed = 60.f;

	// Start the game loop
	while (window.isOpen())
	{

		sf::Time myTime = Clock.getElapsedTime();
		float myftime = myTime.asSeconds();

		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
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
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))centerX = sf::Mouse::getPosition(window).x*0.3;

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Left) angleZ += Speed* myftime;/** ellapsed_time*/;
				if (event.key.code == sf::Keyboard::Right)angleZ -= Speed* myftime/** ellapsed_time*/;
				if (event.key.code == sf::Keyboard::Up)angleY -= Speed* myftime/** ellapsed_time*/;
				if (event.key.code == sf::Keyboard::Down)angleY += Speed* myftime/** ellapsed_time*/;
			}
		}

		window.setActive();

		//glTranslated(0, -10, 0);
		//glRotated(45,0,1,1);

		Dessiner();
		displayFramerate(window, Clock.restart());

		// Update the window
		window.display();
		window.clear();

	}

	return EXIT_SUCCESS;
}

void displayFramerate(sf::RenderWindow& window, sf::Time clock) {
	double framerate = 1 / (clock.asMilliseconds() * 0.001);

	std::ostringstream buff;
	buff<<framerate;
	text_framerate.setString("FPS : "+ buff.str());

	window.pushGLStates();          // Sauvegarde de l'état OpenGL
	window.draw(text_framerate);    // Affichage du texte
	window.popGLStates();           // Restauration de l'état OpenGL
}

void CreateCube(int i, int i1, int i2, int i3, int i4, int i5);

void Dessiner()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(angleY, 0, 1, 0, 0, 0, 0, 0, 1);


	glBegin(GL_QUADS);      // Si cette saloperie n'est pas placée correctement par rapport au glEnd(), erreur de Texture....

	CreateCube(10, 10, 10, 0, 0, 0);
	CreateCube(20, 10, 20, 0, 11, 0);
	CreateCube(10, 10, 10, 0, 22, 0);

	glColor3ub(0, 5, 60); //sol
	glVertex2d(100, 100);
	glVertex2d(100, 0);
	glVertex2d(0, 0);
	glVertex2d(0, 100);

	glEnd();
	glFlush();
}


void CreateCube(int longueur, int largeur, int hauteur, int x, int y, int z)
{

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




/*
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include <gl/glu.h>
#include <iostream>
#include <sstream>

int main(int, char const**)
{
    // Create the main window
    sf::ContextSettings Settings;
    Settings.depthBits = 24; // Request a 24-bit depth buffer
    Settings.stencilBits = 8;  // Request a 8 bits stencil buffer
    Settings.antialiasingLevel = 8;  // Request 2 levels of antialiasing


    sf::RenderWindow window(sf::VideoMode(800, 600, 32), "SFML OpenGL", sf::Style::Close, Settings);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    sf::Font font;
    sf::Text text;

    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "Erreur chargement font" << std::endl;
        return -1;
    }


    text.setFont(font);
    text.setCharacterSize(24); // in pixels, not points!


    // Set color and depth clear value
    glClearDepth(1.f);
    glClearColor(0.f, 0.f, 0.f, 0.f);

    // Enable Z-buffer read and write
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    //glDepthFunc(GL_LESS);

    // Setup a perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective(90.f, 1.f, 1.f, 500.f);
    gluPerspective(70.f, 1.f, 1.f, 500.f);

    sf::Clock Clock;
    sf::Clock Clock2;

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }

            if (event.type == sf::Event::Resized)
                glViewport(0, 0, event.size.width, event.size.height);

        }

        // Clear screen
        window.clear();

        sf::Time myTime = Clock.getElapsedTime();
        float myftime = myTime.asSeconds();

        window.setActive();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.f, 0.f, -200.f);
        glRotatef(myftime * 50, 1.f, 0.f, 0.f);
        glRotatef(myftime * 30, 0.f, 1.f, 0.f);
        glRotatef(myftime * 90, 0.f, 0.f, 1.f);

        glBegin(GL_QUADS);

        glColor3f(1.f, 0.f, 0.f);//red
        glVertex3f(-50.f, -50.f, -50.f);
        glVertex3f(-50.f, 50.f, -50.f);
        glVertex3f(50.f, 50.f, -50.f);
        glVertex3f(50.f, -50.f, -50.f);

        //glColor3f(1.f, 0.f, 0.f);//red
        glColor3f(0.f, 1.f, 1.f);//cyan
        glVertex3f(-50.f, -50.f, 50.f);
        glVertex3f(-50.f, 50.f, 50.f);
        glVertex3f(50.f, 50.f, 50.f);
        glVertex3f(50.f, -50.f, 50.f);

        glColor3f(0.f, 1.f, 0.f);//green
        glVertex3f(-50.f, -50.f, -50.f);
        glVertex3f(-50.f, 50.f, -50.f);
        glVertex3f(-50.f, 50.f, 50.f);
        glVertex3f(-50.f, -50.f, 50.f);

        //glColor3f(0.f, 1.f, 0.f);//green
        glColor3f(1.f, 0.f, 1.f);//magenta
        glVertex3f(50.f, -50.f, -50.f);
        glVertex3f(50.f, 50.f, -50.f);
        glVertex3f(50.f, 50.f, 50.f);
        glVertex3f(50.f, -50.f, 50.f);

        glColor3f(0.f, 0.f, 1.f);//blue
        glVertex3f(-50.f, -50.f, 50.f);
        glVertex3f(-50.f, -50.f, -50.f);
        glVertex3f(50.f, -50.f, -50.f);
        glVertex3f(50.f, -50.f, 50.f);

        //glColor3f(0.f, 0.f, 1.f);//blue
        glColor3f(1.f, 1.f, 0.f);//yellow
        glVertex3f(-50.f, 50.f, 50.f);
        glVertex3f(-50.f, 50.f, -50.f);
        glVertex3f(50.f, 50.f, -50.f);
        glVertex3f(50.f, 50.f, 50.f);

        glEnd();

        sf::Time frameTime = Clock2.restart();
        double framerate = 1 / (frameTime.asMilliseconds() * 0.001);
        std::ostringstream buff;
        buff<<framerate;
        */
/*std::cout << framerate << std::endl;*//*

        text.setString("FPS : "+ buff.str());

        // Update the window
        window.pushGLStates();
        window.draw(text);
        window.popGLStates();
        window.display();
    }

    return EXIT_SUCCESS;
}
*/

