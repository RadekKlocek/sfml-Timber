///////////////////////////////////////////////////////
//Project: Timber
//Module: Graphics
//Creation Date: 20.03.2019
//Author: R.K
/////////////////////////////////////////////////////////
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "SFML/Graphics.hpp"
#include <vector>

extern std::vector<sf::Texture> Textures;
extern std::string GraphPath[];
extern enum class numTexture { BACKGROUND, TREE, BEE, CLOUD, BRANCH, PLAYER, RIP, AXE, LOG };
void TextureInit(std::vector<sf::Texture> t, std::string g[]);

#endif // !GRAPH_HPP
