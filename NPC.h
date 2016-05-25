#pragma once
#include "stdafx.h"
#include "Character.h"

class NPC : public Character
{
public:
	NPC(float initX, float initY, std::string textureID, std::string name, sf::IntRect customHitBox = sf::IntRect(0, 0, 0, 0));
	~NPC();
	
	void Update(float deltaTime, sf::Event ev);
	void Draw(sf::RenderWindow& rw);
	
	sf::Vector2f lastPosition;
	Direction npcDirection;

private:	
	sf::Text message;
	std::vector<std::string> messageList;
};