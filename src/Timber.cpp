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
	float cloud1Speed = 0.0f;
	float cloud2Speed = 0.0f;
	float cloud3Speed = 0.0f;

	//Variable to control time itself
	sf::Clock clock;

	//Time bar
	sf::RectangleShape timeBar;
	float timeBarStartWidth = 400;
	float timeBarHeight = 80;
	timeBar.setSize(sf::Vector2f(timeBarStartWidth, timeBarHeight));
	timeBar.setFillColor(sf::Color::Red);
	timeBar.setPosition((1920 / 2) - timeBarStartWidth / 2, 980);

	sf::Time getTimeTotal;
	float timeRemaining = 6.0f;
	float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining;

	//Track whether the game is running
	bool paused = true;
	
	//Draw some text
	int score = 0;
	sf::Text messageText;
	sf::Text scoreText;

	//We need to choosa a font
	sf::Font font;
	font.loadFromFile("fonts/KOMIKAP_.ttf");

	//Set the font to our message
	messageText.setFont(font);
	scoreText.setFont(font);

	messageText.setString("Press Enter to start!");
	scoreText.setString("Score = 0");

	//Make it really big
	messageText.setCharacterSize(75);
	scoreText.setCharacterSize(100);

	//Choose a color
	messageText.setFillColor(sf::Color::White);
	scoreText.setFillColor(sf::Color::White);

	//Position the text
	sf::FloatRect textRect = messageText.getLocalBounds();
	messageText.setOrigin(textRect.left +
		textRect.width / 2.0f,
		textRect.top +
		textRect.height / 2.0f);
	messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);
	scoreText.setPosition(20, 20);

	while (window.isOpen())
	{
		/*********************************************
		Handle the players input
		*********************************************/
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			paused = false;

			//Reset the time and the score
			score = 0;
			timeRemaining = 5;
		}
		/*********************************************
		Update the scene
		*********************************************/

		if (!paused) {

			//Measure time
			sf::Time dt = clock.restart();

			//Subtract from the amount of time remaining
			timeRemaining -= dt.asSeconds();
			//size up the time bar
			timeBar.setSize(sf::Vector2f(timeBarWidthPerSecond *
				timeRemaining, timeBarHeight));

			if (timeRemaining <= 0.0f)
			{
				//Pause the game
				paused = true;

				//Change the message shown to the player
				messageText.setString("Out of time!!");

				//Reposition the text based on its new size
				sf::FloatRect textRect = messageText.getLocalBounds();
				messageText.setOrigin(textRect.left +
					textRect.width / 2.0f,
					textRect.top +
					textRect.height / 2.0f);
				messageText.setPosition(1920 / 2.0f, 1000 / 2.0f);
			}

			//Setup bee
			if (!beeActive) {
				//How fast is the bee
				srand((int)time(0) * 10);
				beeSpeed = (rand() % 200) + 200;

				//How high is the bee
				srand((int)time(0) * 10);
				float height = (rand() % 500) + 500;
				spriteBee.setPosition(2000, height);
				beeActive = true;
			}
			else
			{
				//Move the bee
				spriteBee.setPosition(spriteBee.getPosition().x -
					(beeSpeed*dt.asSeconds()),
					spriteBee.getPosition().y);
				//Has the bee reached the right hand edge of the screen?
				if (spriteBee.getPosition().x < -60)
				{
					//Set it up ready to be a whole new cloud next frame
					beeActive = false;
				}

			}
			//MANAGE THE CLOUDS
			//Setup cloud1
			if (!cloud1Active) {
				//How fast is the cloud1
				srand((int)time(0) * 10);
				cloud1Speed = (rand() % 200);

				//How high is the bee
				srand((int)time(0) * 10);
				float heigh = (rand() % 150) + 50;
				spriteCloud1.setPosition(-200, heigh);
				cloud1Active = true;
			}
			else
			{
				//Move the cloud1
				spriteCloud1.setPosition(spriteCloud1.getPosition().x +
					(cloud1Speed*dt.asSeconds()),
					spriteCloud1.getPosition().y);
				//Has the cloud reached the right hand edge of the screen?
				if (spriteCloud1.getPosition().x > 1920)
				{
					//Set it up ready to be a whole new cloud next frame
					cloud1Active = false;
				}

			}

			//Setup cloud2
			if (!cloud2Active) {
				//How fast is the bee
				srand((int)time(0) * 20);
				cloud2Speed = (rand() % 200);

				//How high is the bee
				srand((int)time(0) * 20);
				float heigh = (rand() % 300) - 100;
				spriteCloud2.setPosition(-200, heigh);
				cloud2Active = true;
			}
			else
			{
				//Move the cloud2
				spriteCloud2.setPosition(spriteCloud2.getPosition().x +
					(cloud2Speed*dt.asSeconds()),
					spriteCloud2.getPosition().y);
				//Has the cloud reached the right hand edge of the screen?
				if (spriteCloud2.getPosition().x > 1920)
				{
					//Set it up ready to be a whole new cloud next frame
					cloud2Active = false;
				}

			}

			//Setup cloud1
			if (!cloud3Active) {
				//How fast is the bee
				srand((int)time(0) * 30);
				cloud3Speed = (rand() % 200);

				//How high is the bee
				srand((int)time(0) * 30);
				float heigh = (rand() % 450) - 250;
				spriteCloud3.setPosition(-200, heigh);
				cloud3Active = true;
			}
			else
			{
				//Move the cloud3
				spriteCloud3.setPosition(spriteCloud3.getPosition().x +
					(cloud3Speed*dt.asSeconds()),
					spriteCloud3.getPosition().y);
				//Has the cloud reached the right hand edge of the screen?
				if (spriteCloud3.getPosition().x > 1920)
				{
					//Set it up ready to be a whole new cloud next frame
					cloud3Active = false;
				}

			}
		//Update the score text
			std::stringstream ss;
			ss << "Score = " << score;
			scoreText.setString(ss.str());

		} //end if (!paused)
		

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

		//Draw the score
		window.draw(scoreText);

		//Draw the timebar
		window.draw(timeBar);
		if (paused)
		{
			//Draw our message
			window.draw(messageText);
		}

		//Display the window and everything what we draw
		window.display();
	}

	return 0;
}