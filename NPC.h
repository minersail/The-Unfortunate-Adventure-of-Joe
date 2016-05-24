#pragma once
#include "stdafx.h"
#include "Entity.h"

class NPC : public Entity
{
public:
	NPC(float initX, float initY, std::string textureID, std::string name);
	~NPC();
	
	void Update(float deltaTime, sf::Event ev);
	void Draw(sf::RenderWindow& rw);

	sf::Vector2f getLastPosition();
	
	sf::Vector2f lastPosition;
	Direction npcDirection;

private:	
	sf::Text message;
	std::vector<std::string> messageList;

	static const int NPC_WIDTH = 17;
	static const int NPC_HEIGHT = 26;
};