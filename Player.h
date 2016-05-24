#pragma once
#include "stdafx.h"
#include "Character.h"

class Player : public Character
{
public:
	Player(float initX, float initY, std::string textureID, std::string name);
	~Player();

	void Update(float deltaTime, sf::Event ev);
	void Draw(sf::RenderWindow& rw);

	void UpdateChunk();

	Direction keyPressed;

private:
	static const int JOE_HEIGHT = 26;
	static const int JOE_WIDTH = 17;
};
