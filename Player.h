#pragma once
#include "stdafx.h"
#include "Entity.h"

class Player : public Entity {
public:
	Player(float initX, float initY, std::string textureID, std::string name);
	~Player();

	void Update(float deltaTime, sf::Event ev);
	void Walk(Direction _direction);

	void UpdateChunk();

	Direction keyPressed;

private:
	static const int JOE_HEIGHT = 26;
	static const int JOE_WIDTH = 17;
};
