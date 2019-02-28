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

	//Make a tree sprite
	sf::Texture textureTree;
	textureTree.loadFromFile("graphics/tree.png");
	sf::Sprite spriteTree;
	spriteTree.setTexture(textureTree);
	spriteTree.setPosition(810, 0);

	//Prepare the bee
	sf::Texture textureBee;
	textureBee.loadFromFile("graphics/bee.png");
	sf::Sprite spriteBee;
	spriteBee.setTexture(textureBee);
	spriteBee.setPosition(0, 800);
	//Is the bee moving
	bool beeActive = false;
	//Speed the bee
	float beeSpeed = 0.0f;

	//Make three cloud sprites from one texture
	sf::Texture textureCloud;
	textureCloud.loadFromFile("graphics/cloud.png");
	sf::Sprite spriteCloud1;
	sf::Sprite spriteCloud2;
	sf::Sprite spriteCloud3;

	spriteCloud1.setTexture(textureCloud);
	spriteCloud2.setTexture(textureCloud);
	spriteCloud3.setTexture(textureCloud);

	spriteCloud1.setPosition(0, 0);
	spriteCloud2.setPosition(0, 250);
	spriteCloud3.setPosition(0, 500);
	//Are the cloud curently on screen?
	bool cloud1Active = false;
	bool cloud2Active = false;
	bool cloud3Active = false;
	//How speed is each cloud
	float cloud1ASpeed = 0.0f;
	float cloud2ASpeed = 0.0f;
	float cloud3ASpeed = 0.0f;

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
		//Draw the clouds
		window.draw(spriteCloud1);
		window.draw(spriteCloud2);
		window.draw(spriteCloud3);
		//Draw the tree
		window.draw(spriteTree);
		//Draw insects
		window.draw(spriteBee);

		//Display the window and everything what we draw
		window.display();
	}

	return 0;
}