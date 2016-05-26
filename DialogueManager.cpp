#include "stdafx.h"
#include "DialogueManager.h"
#include "Game.h"

DialogueManager::DialogueManager()
	: dialogueBox(0, 0), talkIter(0)
{
	std::vector<std::pair<std::string, int>> D1;
	D1.push_back(std::make_pair("Hello", 0));
	D1.push_back(std::make_pair("Shut up", 1));
	D1.push_back(std::make_pair("Uh.. Goodbye", 0));
	MasterDialogueList.push_back(D1);
}

DialogueManager::~DialogueManager()
{
}

void DialogueManager::Manage(sf::Event ev, sf::RenderWindow& rw)
{
	std::vector<std::pair<std::string, int>> diaSeq = MasterDialogueList[other->dialogueID - 1];

	if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Space)
	{
		if (talkIter == diaSeq.size() - 1)
		{
			Game::_gameState = Game::Playing;
			return;
		}
		else
		{
			talkIter++;
		}
	}
	dialogueBox.SetMessage(diaSeq[talkIter].first);
	dialogueBox.Draw(rw);

	// Create two drawable objects, one for the name of the NPC and the image of it
	sf::Sprite NPCsprite;
	sf::Text NPCname;
	NPCname.setFont(Game::GetFont("Regular"));
	NPCname.setCharacterSize(30);
	NPCname.setColor(sf::Color::Black);

	if (diaSeq[talkIter].second == 0)
	{
		NPCsprite.setTexture(Game::GetResourceManager().Get("Joe"));
		NPCsprite.setTextureRect(sf::IntRect(Game::GetResourceManager().Get("Joe").getSize().x * 2 / 4, 0, 
			Game::GetResourceManager().Get("Joe").getSize().x / 4, Game::GetResourceManager().Get("Joe").getSize().y / 4));
		NPCname.setString("Joe");
	}
	else if (diaSeq[talkIter].second == 1)
	{
		NPCsprite.setTexture(Game::GetResourceManager().Get(other->textureName));
		// Important that all character spritesheets are made with the same formula
		NPCsprite.setTextureRect(sf::IntRect(other->GetTextureRect().width * 2, 0, 
			other->GetTextureRect().width, other->GetTextureRect().height));
		// Use the same name that the Messenger was stored with;
		NPCname.setString(other->name);
	}

	NPCsprite.scale(3, 3);

	NPCsprite.setPosition(dialogueBox.GetPosition().x - SPRITE_OFFSET_X - NPCsprite.getLocalBounds().width / 2, dialogueBox.GetPosition().y - SPRITE_OFFSET_Y);
	NPCname.setPosition(dialogueBox.GetPosition().x - TEXT_OFFSET_X - NPCname.getLocalBounds().width / 2, dialogueBox.GetPosition().y - TEXT_OFFSET_Y);

	rw.draw(NPCname);
	rw.draw(NPCsprite);
}

void DialogueManager::SetNPC(Messenger* otherM)
{
	other = otherM;
	talkIter = 0; // SetNPC is called right before a dialogue sequence
}