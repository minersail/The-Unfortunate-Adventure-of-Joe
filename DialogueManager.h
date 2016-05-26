#pragma once
#include "stdafx.h"
#include "MessageBox.h"
#include "Messenger.h"

/*
Singleton class designed to manage dialogue
*/
class DialogueManager
{
public:
	DialogueManager();
	~DialogueManager();

	void Manage(sf::Event ev, sf::RenderWindow& rw);
	void SetNPC(Messenger* otherM);

	std::vector<std::vector<std::pair<std::string, int>>> MasterDialogueList;

private:
	MessageBox dialogueBox;
	// Change to vector later
	Messenger* other;

	int talkIter;

	// Offsets from the center of the MessageBox
	const int SPRITE_OFFSET_X = 335;
	const int SPRITE_OFFSET_Y = 30;
	const int TEXT_OFFSET_X = 320;
	const int TEXT_OFFSET_Y = 70;
};