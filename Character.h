#pragma once
#include "stdafx.h"
#include "Entity.h"

class Character : public Entity
{
public:
	Character(float initX, float initY, std::string textureID, std::string name, int charW, int charH, sf::IntRect hitBox);
	~Character();

	void Walk(Direction dir);

protected:
	int characterWidth;
	int characterHeight;

	int speed;
};