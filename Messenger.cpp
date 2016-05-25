#include "stdafx.h"
#include "Messenger.h"
#include "Game.h"

Messenger::Messenger(float initX, float initY, std::string textureID, std::string name,
					 sf::Vector2i pos1, sf::Vector2i pos2, sf::Vector2i pos3, sf::Vector2i pos4)
	: Entity(initX, initY, textureID, name)
{
	if (pos1 != sf::Vector2i(-1, -1))
	{
		activationLocs.push_back(pos1);
	}
	if (pos2 != sf::Vector2i(-1, -1))
	{
		activationLocs.push_back(pos2);
	}
	if (pos3 != sf::Vector2i(-1, -1))
	{
		activationLocs.push_back(pos3);
	}
	if (pos4 != sf::Vector2i(-1, -1))
	{
		activationLocs.push_back(pos4);
	}
}

Messenger::~Messenger()
{
}

void Messenger::Update(float deltaTime, sf::Event ev)
{
	if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Space)
	{
		if (Game::GetJoe()->GetPosition().x == 
	}
}