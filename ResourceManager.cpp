#include "stdafx.h"
#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
	Load("images/tileset.png", "Tiles");
	Load("images/joe.png", "Joe");
	Load("images/water.png", "Water");
	Load("images/stonehut.png", "Stone Hut");
}

ResourceManager::~ResourceManager()
{
	std::map<std::string, sf::Texture*>::iterator it = TextureList.begin();
	while (it != TextureList.end())
	{
		delete it->second;
		it++;
	}
}

void ResourceManager::Load(std::string filename, std::string texturename)
{
	sf::Texture* t1 = new sf::Texture();
	assert(t1->loadFromFile(filename));
	TextureList.insert(std::make_pair(texturename, t1));
}

sf::Texture& ResourceManager::Get(std::string texturename)
{
	return *(TextureList.find(texturename)->second);
}