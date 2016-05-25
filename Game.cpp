#include "stdafx.h"
#include "Game.h"
#include "Map.h"
#include "Player.h"
#include "Barrier.h"
#include "Decoration.h"
#include "NPC.h"

void Game::Start()
{
	if (_gameState != Uninitialized)
		return;

	_mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "The Unfortunate Adventure of Joe");
	_mainWindow.setFramerateLimit(60);

	_view.setCenter(sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));
	_view.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	_mainWindow.setView(_view);

	// Pointer name means absolutely nothing////////////////////////////////////////////////////////
	Map* board0 = new Map(0, 0, "Tiles", "Map", sf::Vector2i(16, 16), "maps/blank.txt", 50, 50);
	Map* board1 = new Map(50, 0, "Tiles", "Map 2", sf::Vector2i(16, 16), "maps/blank.txt", 50, 50);
	Map* board2 = new Map(100, 0, "Tiles", "Map 3", sf::Vector2i(16, 16), "maps/7.txt", 50, 50);
	Map* board3 = new Map(0, 50, "Tiles", "Map 4", sf::Vector2i(16, 16), "maps/blank.txt", 50, 50);
	Map* board4 = new Map(50, 50, "Tiles", "Map 5", sf::Vector2i(16, 16), "maps/blank.txt", 50, 50);
	Map* board5 = new Map(100, 50, "Tiles", "Map 6", sf::Vector2i(16, 16), "maps/blank.txt", 50, 50);
	Map* board6 = new Map(0, 100, "Tiles", "Map 7", sf::Vector2i(16, 16), "maps/6.txt", 50, 50);
	Map* board7 = new Map(50, 100, "Tiles", "Map 8", sf::Vector2i(16, 16), "maps/blank.txt", 50, 50);
	Map* board8 = new Map(100, 100, "Tiles", "Map 9", sf::Vector2i(16, 16), "maps/blank.txt", 50, 50);

	//////////////////////////////////GAME BORDERS///////////////////////////////////////////
	Barrier* NorthBorder = new Barrier(0, 0, "Fence", "North Border", sf::Vector2i(149, 1));
	Barrier* SouthBorder = new Barrier(0, 149, "Fence", "South Border", sf::Vector2i(149, 1));
	Barrier* EastBorder = new Barrier(149, 0, "Fence", "East Border", sf::Vector2i(1, 149));
	Barrier* WestBorder = new Barrier(0, 0, "Fence", "West Border", sf::Vector2i(1, 149));
	/////////////////////////////////////////////////////////////////////////////////////////

	// Tile 6
	Barrier* animLake = new Barrier(37, 137, "Water", "lake 1", sf::Vector2i(5, 5), 3);
	Barrier* hut1 = new Barrier(30, 136, "Blue House", "hut 1", 1, sf::IntRect(0, 26, 80, 70));
	Barrier* fence5 = new Barrier(50, 100, "Fence", "Orchard Lake East Fence", sf::Vector2i(1, 50));
	Decoration* grass1 = new Decoration(38, 137, "Grass Side", "grass 1", sf::Vector2i(3, 1));
	Decoration* grass2 = new Decoration(38, 141, "Grass Side", "grass 2", sf::Vector2i(3, 1), 180);
	Decoration* grass3 = new Decoration(37, 138, "Grass Side", "grass 3", sf::Vector2i(1, 3), 270);
	Decoration* grass4 = new Decoration(41, 138, "Grass Side", "grass 4", sf::Vector2i(1, 3), 90);
	Decoration* grass5 = new Decoration(37, 137, "Grass Corner 2", "grass 5");
	Decoration* grass6 = new Decoration(37, 142, "Grass Corner 2", "grass 6", 270);
	Decoration* grass7 = new Decoration(42, 142, "Grass Corner 2", "grass 7", 180);
	Decoration* grass8 = new Decoration(42, 137, "Grass Corner 2", "grass 8", 90);
	
	// Tile 3
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			Barrier* hut = new Barrier(6 + i * 6, 59 + j * 10, "Blue House", "hut " + std::to_string(i + j * 4), 1, sf::IntRect(0, 26, 80, 70));
		}
		for (int i = 0; i < 3; i++)
		{
			Barrier* hut = new Barrier(27 + i * 6, 59 + j * 10, "Blue House", "hut " + std::to_string(i + j * 4 + 4), 1, sf::IntRect(0, 26, 80, 70));
		}
	}

	// ------------------------------------------Things drawn under Joe go above here------------------------------------------------
	NPC* bob = new NPC(32, 120, "NPC 1", "Bob");
	NPC* bob1 = new NPC(32, 120, "NPC 1", "Bobb");
	NPC* bob2 = new NPC(32, 120, "NPC 1", "Bobbb");
	NPC* bob3 = new NPC(32, 120, "NPC 1", "Bbob");
	NPC* bob4 = new NPC(32, 120, "NPC 1", "Booob");
	NPC* bob5 = new NPC(32, 120, "NPC 1", "Boooob");
	NPC* bob6 = new NPC(32, 120, "NPC 1", "Bboob");
	NPC* bob7 = new NPC(32, 120, "NPC 1", "Baob");
	NPC* bob8 = new NPC(32, 120, "NPC 1", "Bofb");
	NPC* bob9 = new NPC(32, 120, "NPC 1", "Bsob");
	NPC* bob10 = new NPC(32, 120, "NPC 1", "Bodb");
	NPC* bob11 = new NPC(32, 120, "NPC 1", "aBob");	
	
	Player* joe = new Player(34, 142, "Joe", "Joe");
	// ------------------------------------------Things drawn over Joe go below here-------------------------------------------------

	// Tile 6
	Decoration* hut1top = new Decoration(30, 136, "Blue House Roof", "hut 1 roof");
	
	// Tile 3
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			Decoration* hut = new Decoration(6 + i * 6, 59 + j * 10, "Blue House Roof", "hut " + std::to_string(i + j * 4) + "roof");
		}
		for (int i = 0; i < 3; i++)
		{
			Decoration* hut = new Decoration(27 + i * 6, 59 + j * 10, "Blue House Roof", "hut " + std::to_string(i + j * 4 + 4) + "roof");
		}
	}

	///////////////////////////////////////////////////////////////////////////////////////////
	LoadFonts();

	_gameState = Playing;

	while (!IsExiting())
	{
		GameLoop();
	}

	_mainWindow.close();
}

bool Game::IsExiting()
{
	if (_gameState == Exiting)
		return true;
	else
		return false;
}

void Game::GameLoop()
{
	sf::Event currentEvent;
	_mainWindow.pollEvent(currentEvent);

	switch (_gameState)
	{
	case Playing:
	{
		_mainWindow.clear();

		_collisionManager.Update();

		_gameObjectManager.UpdateAll(currentEvent); // Most important lines of code:
		_gameObjectManager.DrawAll(_mainWindow);    // They update and draw all sprites

		_mainWindow.display();
		break;
	}
	case Paused:
	{
		_gameState = Playing;
		break;
	}
	case GameOver:
	{
		_gameObjectManager.DrawAll(_mainWindow);
		_mainWindow.display();
		break;
	}
	}

	if (currentEvent.type == sf::Event::Closed)
		_gameState = Exiting;
	if (currentEvent.type == sf::Event::KeyPressed)
	{
		if (currentEvent.key.code == sf::Keyboard::Escape)
			_gameState = Paused;
	}
}

void Game::LoadFonts()
{
	regular.loadFromFile("fonts/regular.ttf");
}

sf::RenderWindow& Game::GetWindow()
{
	return _mainWindow;
}

GameObjectManager& Game::GetObjectManager()
{
	return _gameObjectManager;
}

ResourceManager& Game::GetResourceManager()
{
	return _resourceManager;
}

CollisionManager& Game::GetCollisionManager()
{
	return _collisionManager;
}

Player* Game::GetJoe()
{
	return dynamic_cast<Player*>(_gameObjectManager.Get("Joe"));
}

void Game::SetView(float newX, float newY)
{
	_view.setCenter(newX, newY); // Adjusts the center of the view
	_mainWindow.setView(_view); // Applies view
}

void Game::Initialize(std::string name, VisibleGameObject* obj, float x, float y)
{
	_gameObjectManager.Add(name, obj);
	obj->SetPosition(x, y);
}

Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;
ResourceManager Game::_resourceManager;
CollisionManager Game::_collisionManager;
sf::Font Game::regular;
sf::View Game::_view;