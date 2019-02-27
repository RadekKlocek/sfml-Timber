#include "Timber.hpp"

int main()
{
	//Create a video mode object
	sf::VideoMode vm(1920, 1080);

	//Create and open a window for a game
	sf::RenderWindow window(vm, "Timber", sf::Style::Fullscreen);

	//Create teksture to hold background in GPU
	sf::Texture textureBackground;

	//Load a graphics into teksture'
	textureBackground.loadFromFile("graphics/background.png");

	//Create a sprite
	sf::Sprite spriteBackground;

	//Attach the teksture to the sprite
	spriteBackground.setTexture(textureBackground);

	//Set the spriteBackground to cover the screen
	spriteBackground.setPosition(0, 0);

	while (window.isOpen())
	{
		/*********************************************
		Handle the players input
		*********************************************/
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		/*********************************************
		Update the scene
		*********************************************/

		/*********************************************
		Draw the scene
		*********************************************/
		//Clear everything from the last frame
		window.clear();

		//Draw the scene here
		window.draw(spriteBackground);

		//Display the window and everything what we draw
		window.display();
	}

	return 0;
}