#include "stdafx.h"
#include "Game.h"
#include "Map.h"
#include "Player.h"
#include "Barrier.h"
#include "Decoration.h"

void Game::Start()
{
	if (_gameState != Uninitialized)
		return;

	_mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "The Unfortunate Adventure of Joe");
	_mainWindow.setFramerateLimit(60);

	_view.setCenter(sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));
	_view.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	_mainWindow.setView(_view);

	// Pointer name means absolutely nothing
	Map* board = new Map(0, 0, "Tiles", "Map", sf::Vector2i(16, 16), "maps/blank.txt", 50, 50);
	Map* board2 = new Map(50, 0, "Tiles", "Map 2", sf::Vector2i(16, 16), "maps/square.txt", 50, 50);
	Map* board3 = new Map(100, 0, "Tiles", "Map 3", sf::Vector2i(16, 16), "maps/blank.txt", 50, 50);
	Map* board4 = new Map(0, 50, "Tiles", "Map 4", sf::Vector2i(16, 16), "maps/square.txt", 50, 50);
	Map* board5 = new Map(50, 50, "Tiles", "Map 5", sf::Vector2i(16, 16), "maps/4.txt", 50, 50);
	Map* board6 = new Map(100, 50, "Tiles", "Map 6", sf::Vector2i(16, 16), "maps/square.txt", 50, 50);
	Map* board7 = new Map(0, 100, "Tiles", "Map 7", sf::Vector2i(16, 16), "maps/blank.txt", 50, 50);
	Map* board8 = new Map(50, 100, "Tiles", "Map 8", sf::Vector2i(16, 16), "maps/7.txt", 50, 50);
	Map* board9 = new Map(100, 100, "Tiles", "Map 9", sf::Vector2i(16, 16), "maps/square.txt", 50, 50);

	Barrier* NorthBorder = new Barrier(0, 0, "Fence", "North Border", sf::Vector2i(149, 1));
	Barrier* SouthBorder = new Barrier(0, 148, "Fence", "South Border", sf::Vector2i(149, 1));
	Barrier* EastBorder = new Barrier(148, 0, "Fence", "East Border", sf::Vector2i(1, 149));
	Barrier* WestBorder = new Barrier(0, 0, "Fence", "West Border", sf::Vector2i(1, 149));

	Barrier* animLake = new Barrier(87, 87, "Water", "lake 1", sf::Vector2i(5, 5), 3);
	Barrier* hut1 = new Barrier(81, 88, "Stone Hut", "hut 1", 2);
	Barrier* fencen1 = new Barrier(50, 51, "Fence", "Home North Fence 1", sf::Vector2i(23, 1));
	Barrier* fencen2 = new Barrier(77, 51, "Fence", "Home North Fence 2", sf::Vector2i(23, 1));
	Barrier* fence2 = new Barrier(50, 99, "Fence", "Home South Fence 1", sf::Vector2i(23, 1));
	Barrier* fence3 = new Barrier(77, 99, "Fence", "Home South Fence 2", sf::Vector2i(23, 1));
	Barrier* fence4 = new Barrier(50, 51, "Fence", "Home West Fence", sf::Vector2i(1, 48));
	Barrier* fence5 = new Barrier(100, 51, "Fence", "Home East Fence", sf::Vector2i(1, 49));
	Decoration* grass1 = new Decoration(88, 87, "Grass Side", "grass 1", sf::Vector2i(3, 1));
	Decoration* grass2 = new Decoration(88, 91, "Grass Side", "grass 2", sf::Vector2i(3, 1), 180);
	Decoration* grass3 = new Decoration(87, 88, "Grass Side", "grass 3", sf::Vector2i(1, 3), 270);
	Decoration* grass4 = new Decoration(91, 88, "Grass Side", "grass 4", sf::Vector2i(1, 3), 90);
	Decoration* grass5 = new Decoration(87, 87, "Grass Corner 2", "grass 5");
	Decoration* grass6 = new Decoration(87, 92, "Grass Corner 2", "grass 6", 270);
	Decoration* grass7 = new Decoration(92, 92, "Grass Corner 2", "grass 7", 180);
	Decoration* grass8 = new Decoration(92, 87, "Grass Corner 2", "grass 8", 90);
	
	Barrier* fence6 = new Barrier(50, 100, "Fence", "West Fence 1", sf::Vector2i(1, 48));
	Barrier* fence7 = new Barrier(100, 100, "Fence", "East Fence 1", sf::Vector2i(1, 48));
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			Barrier* hut = new Barrier(57 + i * 4, 110 + j * 10, "Stone Hut", "hut " + std::to_string(i + j * 4), 2);
		}
		for (int i = 0; i < 4; i++)
		{
			Barrier* hut = new Barrier(77 + i * 4, 110 + j * 10, "Stone Hut", "hut " + std::to_string(i + j * 4 + 4), 2);
		}
	}

	Player* joe = new Player(84, 92, "Joe", "Joe");

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