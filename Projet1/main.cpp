#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include <gl/glu.h>

int main(int, char const**)
{
	// Create the main window
	sf::ContextSettings Settings;
	Settings.depthBits = 24; // Request a 24-bit depth buffer
	Settings.stencilBits = 8;  // Request a 8 bits stencil buffer
	Settings.antialiasingLevel = 0;  // Request 2 levels of antialiasing
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "SFML OpenGL", sf::Style::Close, Settings);



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

	// Start the game loop
	while (window.isOpen())
	{
		Sleep(100);
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

		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
}
