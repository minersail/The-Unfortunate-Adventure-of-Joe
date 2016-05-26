#include "stdafx.h"
#include "UseObject.h"
#include "Game.h"

UseObject::UseObject(float initX, float initY, std::string textureID, std::string name, sf::IntRect hitbox)
	: Entity(initX, initY, textureID, name, hitbox)
{
}

UseObject::~UseObject()
{
}

bool UseObject::CheckUsePoints(sf::Event ev)
{
	if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Space)
	{
		float pX = Game::GetJoe()->GetPosition().x + Game::GetJoe()->GetHitBox().left;
		float pY = Game::GetJoe()->GetPosition().y + Game::GetJoe()->GetHitBox().top;

		std::vector<UsePoint>::iterator it = activationLocs.begin();
		while (it != activationLocs.end())
		{
			sf::RectangleShape unit;
			unit.setSize(sf::Vector2f(16, 16));
			unit.setPosition(it->x * 16, it->y * 16 - 8); // Adjust the UsePoints by half a unit

			if (unit.getGlobalBounds().contains(pX, pY))
			{
				sf::IntRect joeRect = Game::GetJoe()->GetTextureRect();
				if (joeRect.left == joeRect.width * 0 && it->dir == Up)
					return true;
				if (joeRect.left == joeRect.width * 1 && it->dir == Right)
					return true;
				if (joeRect.left == joeRect.width * 2 && it->dir == Down)
					return true;
				if (joeRect.left == joeRect.width * 3 && it->dir == Left)
					return true;
			}

			it++;
		}
	}
	return false;
}