#pragma once
#include "stdafx.h"
#include "Character.h"

Character::Character(float initX, float initY, std::string textureID, std::string name, int charW, int charH, sf::IntRect hitBox)
	: Entity(initX, initY, textureID, name, hitBox), speed(2)
{
	characterWidth = charW;
	characterHeight = charH;

	SetTextureRect(0, 0, charW, charH);
	GetSprite().setOrigin(charW / 2, charH / 2);
}

Character::~Character()
{
}

void Character::Walk(Direction dir)
{
	frameCount += 1;
	switch (dir)
	{
		case Up:
		{
			SetTextureRect(0, GetSprite().getTextureRect().top, characterWidth, characterHeight);
			SetPosition(GetPosition().x, GetPosition().y - speed);
			break;
		}
		case Down:
		{
			SetTextureRect(characterWidth * 2, GetSprite().getTextureRect().top, characterWidth, characterHeight);
			SetPosition(GetPosition().x, GetPosition().y + speed);
			break;
		}
		case Left:
		{
			SetTextureRect(characterWidth * 3, GetSprite().getTextureRect().top, characterWidth, characterHeight);
			SetPosition(GetPosition().x - speed, GetPosition().y);
			break;
		}
		case Right:
		{
			SetTextureRect(characterWidth * 1, GetSprite().getTextureRect().top, characterWidth, characterHeight);
			SetPosition(GetPosition().x + speed, GetPosition().y);
			break;
		}
		case None:
		{
			SetTextureRect(GetSprite().getTextureRect().left, 0, characterWidth, characterHeight);
			return;
			break;
		}
	}

	if (frameCount % 10 == 0)
	{
		if (GetSprite().getTextureRect().top != 78)
		{
			SetTextureRect(GetSprite().getTextureRect().left, GetSprite().getTextureRect().top + characterHeight, characterWidth, characterHeight);
		}
		else
		{
			SetTextureRect(GetSprite().getTextureRect().left, 0, characterWidth, characterHeight);
		}
	}
}