#include <vector>
#include <string>

#include "Graph.hpp"

using namespace std;

//enum class numTexture { BACKGROUND, TREE, BEE, CLOUD, BRANCH, PLAYER, RIP, AXE, LOG }; //names of textures
enum class numSprite { BACKGROUND, TREE, BEE, CLOUD, BRANCH, PLAYER, RIP, AXE, LOG };  //name of sprites

//vector<sf::Texture> Textures(static_cast<int>(numTexture::LOG) + 1);
//vector<sf::Sprite> Sprites(static_cast<int>(numSprite::LOG) + 1);

string GraphPath[] = {
	"graphics/background.png",
	"graphics/tree.png",
	"graphics/bee.png",
	"graphics/cloud.png",
	"graphics/branch.png",
	"graphics/player.png",
	"graphics/rip.png",
	"graphics/axe.png",
	"graphics/log.png"
};

void TextureInit(vector<sf::Texture> t, string g[])
{
	for (int i = 0; i <= static_cast<int>(numTexture::LOG); i++)
	{
		t[i].loadFromFile(g[i]);
	}
}