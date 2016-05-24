#include "stdafx.h"
#include "NPC.h"
#include "Game.h"

/*NPC::NPC(float initX, float initY, std::string textureID, std::string name)
	: Entity(initX, initY, textureID, name)
{
	ticks = rand() % 120;
	messageList.push_back("");
	messageList.push_back("Wow, it's slightly unconfortable \nout, Joe must be nearby");
	messageList.push_back("Don't you think that\nLIBERALS are awesome?");
	messageList.push_back("You know, I heard Joe reproduces \nby budding.");
	messageList.push_back("If you think this game is rigged:\nIt is.");
	messageList.push_back("EU4 is better than\nCiv 5");
	messageList.push_back("Doctor Who is overrated");
	messageList.push_back("Hamachi was a great invention");
	messageList.push_back("I'm taking US History over the \nsummer so I can have more Mr. Beck!");
	messageList.push_back("I really like doing \nPrezi presentations");
	messageList.push_back("Ronald Raegan was ok \nI guess");
	messageList.push_back("Des Stone's photography is\nbetter than Joe's");
	messageList.push_back("Modded gameplay is the lifeblood\nof gaming");
	messageList.push_back("Bernie Sanders for president");
	messageList.push_back("Apple is better than Android");
	messageList.push_back("Carbon Leaf is mediocre");
	messageList.push_back("I'm so hyped about being hyped!");
	messageList.push_back("Global warming is real");

	message.setFont(Game::regular);
	message.setCharacterSize(12);
	message.setColor(sf::Color(0, 0, 0));
	message.setString(messageList[0]);
	message.setOrigin(message.getLocalBounds().width / 2, message.getLocalBounds().height / 2);
}

sf::Vector2f NPC::getLastPosition(){
	return lastPosition;
}

void NPC::update(sf::Event ev)
{
	ticks++;

	if (ticks % 120 == 0)
	{
		npcDirection = static_cast<direction>(rand() % 5);
	}

	if (ticks % 300 == 0)
	{
		message.setString(messageList[0]);
		message.setOrigin(message.getLocalBounds().width / 2, message.getLocalBounds().height / 2);
	}

	else if (ticks % 150 == 0)
	{
		message.setString(messageList[(rand() % messageList.size() - 1) + 1]);
		message.setOrigin(message.getLocalBounds().width / 2, message.getLocalBounds().height / 2);
	}

	switch (npcDirection)
	{
		if (lastPosition.x == sprite.getPosition().x && lastPosition.y == sprite.getPosition().y && npcDirection != none)
		{
			ticks = 120;
			std::cout << "DANK MEME#MEMEEMFREGF" << std::endl;
			/*if (npcDirection == up)
			{
				npcDirection = down;
			}
			else if (npcDirection == down)
			{
				npcDirection = up;
			}
			else if (npcDirection == left)
			{
				npcDirection = right;
			}
			else if (npcDirection == right)
			{
				npcDirection = left;
			}
		}
		case up:
		{
			textureRect.left = 0;
			sprite.setPosition(sprite.getPosition().x , sprite.getPosition().y - 2);
			break;
		}
		case down:
		{
			textureRect.left = 34;
			sprite.setPosition(sprite.getPosition().x , sprite.getPosition().y + 2);
			break;
		}
		case left:
		{
			textureRect.left = 51;
			sprite.setPosition(sprite.getPosition().x - 2, sprite.getPosition().y);
			break;
		}
		case right:
		{
			textureRect.left = 17;
			sprite.setPosition(sprite.getPosition().x + 2, sprite.getPosition().y);
			break;
		}
		case none:
		{
			textureRect.top = 0;
			sprite.setTextureRect(textureRect);
			return;
			break;
		}
	}

	if (ticks % 10 == 0)
	{
		if (textureRect.top != 78)
		{
			textureRect.top += NPC_HEIGHT;
		}
		else
		{
			textureRect.top = 0;
		}
	}

	
	sprite.setTextureRect(textureRect);

	message.setPosition(getPosition().x, getPosition().y - NPC_HEIGHT);
	lastPosition.x = sprite.getPosition().x;
	lastPosition.y = sprite.getPosition().x;
}

void NPC::draw(sf::RenderWindow& rw)
{
	rw.draw(sprite);
	rw.draw(message);
}*/