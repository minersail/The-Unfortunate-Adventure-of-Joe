#include "stdafx.h"
#include "Game.h"
#include "Map.h"
#include "Player.h"
#include "Barrier.h"

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
	Map* board2 = new Map(800, 0, "Tiles", "Map 2", sf::Vector2i(16, 16), "maps/square.txt", 50, 50);
	Map* board3 = new Map(1600, 0, "Tiles", "Map 3", sf::Vector2i(16, 16), "maps/blank.txt", 50, 50);
	Map* board4 = new Map(0, 800, "Tiles", "Map 4", sf::Vector2i(16, 16), "maps/square.txt", 50, 50);
	Map* board5 = new Map(800, 800, "Tiles", "Map 5", sf::Vector2i(16, 16), "maps/blank.txt", 50, 50);
	Map* board6 = new Map(1600, 800, "Tiles", "Map 6", sf::Vector2i(16, 16), "maps/square.txt", 50, 50);
	Map* board7 = new Map(0, 1600, "Tiles", "Map 7", sf::Vector2i(16, 16), "maps/blank.txt", 50, 50);
	Map* board8 = new Map(800, 1600, "Tiles", "Map 8", sf::Vector2i(16, 16), "maps/square.txt", 50, 50);
	Map* board9 = new Map(1600, 1600, "Tiles", "Map 9", sf::Vector2i(16, 16), "maps/square.txt", 50, 50);
	Player* joe = new Player(1200, 1200, "Joe", "Joe");
	Barrier* lake = new Barrier(1000, 1000, "Water", "lake 1", sf::Vector2i(5, 5));
	Barrier* animLake = new Barrier(1400, 1400, "Water", "lake 2", sf::Vector2i(5, 5), 3);
	Barrier* hut = new Barrier(1008, 1392, "Stone Hut", "hut 1", 2);

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