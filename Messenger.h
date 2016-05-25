#pragma once
#include "stdafx.h"
#include "Entity.h"

class Messenger : public Entity
{
public:
	Messenger(float initX, float initY, std::string textureID, std::string name, sf::Vector2i pos1 = sf::Vector2i(-1, -1),
		sf::Vector2i pos2 = sf::Vector2i(-1, -1), sf::Vector2i pos3 = sf::Vector2i(-1, -1), sf::Vector2i pos4 = sf::Vector2i(-1, -1));
	~Messenger();

	void Update(float deltaTime, sf::Event ev);

private:
	std::vector<sf::Vector2i> activationLocs;
};