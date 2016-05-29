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

	std::vector<std::pair<std::string, int>> D2;
	D2.push_back(std::make_pair("Who are you?", 0));
	D2.push_back(std::make_pair("I......uh.....", 1));
	D2.push_back(std::make_pair("What are you doing in my house?", 0));
	D2.push_back(std::make_pair("Err......um.....", 1));
	D2.push_back(std::make_pair("*Explosive Fart*", 1));
	D2.push_back(std::make_pair("Oh god you can keep the house", 0));
	MasterDialogueList.push_back(D2);
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
			if (Game::GetPlayer()->GetPosition().x > 0) // If player is in the building chunk
			{
				Game::_gameState = Game::Playing;
			}
			else
			{
				Game::_gameState = Game::InBuilding;
			}
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
		NPCsprite.setTexture(Game::GetResourceManager().Get(Game::GetPlayer()->textureName));
		NPCsprite.setTextureRect(sf::IntRect(Game::GetResourceManager().Get(Game::GetPlayer()->textureName).getSize().x * 2 / 4, 0,
			Game::GetResourceManager().Get(Game::GetPlayer()->textureName).getSize().x / 4, Game::GetResourceManager().Get(Game::GetPlayer()->textureName).getSize().y / 4));
		NPCname.setString(Game::GetPlayer()->name);
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