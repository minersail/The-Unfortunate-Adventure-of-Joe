#include "stdafx.h"
#include "Game.h"
#include "Map.h"
#include "Player.h"
#include "Barrier.h"
#include "Decoration.h"
#include "NPC.h"
#include "Messenger.h"
#include "Building.h"

void Game::Start()
{
	if (_gameState != Uninitialized)
		return;

	_mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "The Unfortunate Adventure of Joe");
	_mainWindow.setFramerateLimit(60);

	_view.setCenter(sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));
	_view.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	_mainWindow.setView(_view);

	_editingBuilding = false;
	_currentBuilding = NULL;

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
	//Barrier* hut1 = new Barrier(30, 136, "Blue House", "hut 1", 1, sf::IntRect(0, 26, 80, 70));
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

	// House 1
	Building* JoeHouse = new Building(30, 136, "Blue House", "Joe's House", UseObject::UsePoint(32, 142, Entity::Up), UseObject::UsePoint(-25, 33, Entity::Down), sf::IntRect(0, 26, 80, 70));
	SwitchObjectManager(false);
	Map* floor1 = new Map(-35, 15, "Building Tiles", "Bottom Floor", sf::Vector2i(16, 16), "maps/joehouse.txt", 20, 20);
	Barrier* wall1 = new Barrier(-35, 15, "Floor", "North Wall", sf::Vector2i(20, 1));
	Barrier* wall2 = new Barrier(-35, 34, "Floor", "South Wall", sf::Vector2i(20, 1));
	Barrier* wall3 = new Barrier(-16, 15, "Floor", "East Wall", sf::Vector2i(1, 20));
	Barrier* wall4 = new Barrier(-35, 15, "Floor", "West Wall", sf::Vector2i(1, 20));
	Decoration* walld1 = new Decoration(-35, 15, "Wall", "North Wall Decoration", sf::Vector2i(20, 1), 90);
	Decoration* walld2 = new Decoration(-35, 34, "Wall", "South Wall Decoration", sf::Vector2i(20, 1), 270);
	Decoration* walld3 = new Decoration(-16, 15, "Wall", "East Wall Decoration", sf::Vector2i(1, 20), 180);
	Decoration* walld4 = new Decoration(-35, 15, "Wall", "West Wall Decoration", sf::Vector2i(1, 20), 0);
	Decoration* wallc1 = new Decoration(-15, 15, "Wall Corner", "Wall Corner 1", 90);
	Decoration* wallc2 = new Decoration(-35, 35, "Wall Corner", "Wall Corner 2", 270);
	Decoration* wallc3 = new Decoration(-15, 35, "Wall Corner", "Wall Corner 3", 180);
	Decoration* wallc4 = new Decoration(-35, 15, "Wall Corner", "Wall Corner 4", 0);
	Decoration* door = new Decoration(-24, 35, "Door", "Door", 180);
	Messenger* oldman = new Messenger(-25, 30, "Old Man", "Old Fart", 2);
	JoeHouse->SetFloorManager(_buildingObjectMananger);
	SwitchObjectManager(true);

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
	
	Player* joe = new Player(34, 142, "Will", "Joe");

	Messenger* larry = new Messenger(24, 137, "NPC 2", "Steve", 1);
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
	case InBuilding: // Buildings require their own GameState because they have their own GameObjectManager and EntityLists
	{
		_mainWindow.clear();
		_collisionManager.CheckChunkCollisions(-1);

		_currentBuilding->GetFloorManager().UpdateAll(currentEvent);
		_currentBuilding->GetFloorManager().DrawAll(_mainWindow);
		_mainWindow.display();

		if (currentEvent.type == sf::Event::KeyPressed && currentEvent.key.code == sf::Keyboard::Space)
		{
			float pX = GetPlayer()->GetPosition().x; // Hitbox's origin
			float pY = GetPlayer()->GetPosition().y;
			UseObject::UsePoint EP = _currentBuilding->exitPoint;

			sf::RectangleShape unit;
			unit.setSize(sf::Vector2f(16, 16));
			unit.setPosition(EP.x * 16, EP.y * 16);

			// Debug for Door--KEEP
			/*unit.setFillColor(sf::Color::Red);
			Game::GetWindow().draw(unit);
			Game::GetWindow().display();*/

			if (unit.getGlobalBounds().contains(pX, pY))
			{
				sf::IntRect joeRect = GetPlayer()->GetTextureRect();
				if ((joeRect.left == joeRect.width * 0 && EP.dir == Entity::Up) || (joeRect.left == joeRect.width * 1 && EP.dir == Entity::Right)
					|| (joeRect.left == joeRect.width * 2 && EP.dir == Entity::Down) || (joeRect.left == joeRect.width * 3 && EP.dir == Entity::Left))
				{
					LockView(false);
					GetPlayer()->SetPosition(_currentBuilding->GetActivationLocations()[0].x * 16, _currentBuilding->GetActivationLocations()[0].y * 16);
					_currentBuilding = NULL;
					_gameState = Game::Playing;
					return;
				}
			}
		}
		break;
	}
	case Talking:
	{
		_mainWindow.clear();
		
		if (_currentBuilding != NULL) // Joe is currently in a building
		{
			_currentBuilding->GetFloorManager().DrawAll(_mainWindow);
		}
		else
		{
			_gameObjectManager.DrawAll(_mainWindow);
		}

		_dialogueManager.Manage(currentEvent, _mainWindow);
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

sf::Font& Game::GetFont(std::string fontID)
{
	if (fontID == "Regular")
	{
		return regular;
	}
}

sf::RenderWindow& Game::GetWindow()
{
	return _mainWindow;
}

GameObjectManager& Game::GetObjectManager()
{
	if (_editingBuilding)
	{
		return _buildingObjectMananger;
	}
	else
	{
		return _gameObjectManager;
	}
}

void Game::SwitchObjectManager(bool toMain)
{
	if (toMain)
	{
		_editingBuilding = false;
		_buildingObjectMananger.Clear();
	}
	else
	{
		_editingBuilding = true;
	}
}

void Game::StartBuildingMode(Building* building)
{
	_currentBuilding = building;
	_gameState = InBuilding;
}

ResourceManager& Game::GetResourceManager()
{
	return _resourceManager;
}

CollisionManager& Game::GetCollisionManager()
{
	return _collisionManager;
}

DialogueManager& Game::GetDialogueManager()
{
	return _dialogueManager;
}

Player* Game::GetPlayer()
{
	return dynamic_cast<Player*>(_gameObjectManager.Get("Joe"));
}

sf::Vector2i Game::GTS(std::string textureID)
{
	return sf::Vector2i(_resourceManager.Get(textureID).getSize());
}

void Game::SetView(float newX, float newY)
{
	if (!_screenLocked)
	{
		_view.setCenter(newX, newY); // Adjusts the center of the view
		_mainWindow.setView(_view); // Applies view
	}
}

void Game::LockView(bool lock)
{
	_screenLocked = lock;
}

Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;
GameObjectManager Game::_buildingObjectMananger;
ResourceManager Game::_resourceManager;
CollisionManager Game::_collisionManager;
DialogueManager Game::_dialogueManager;
sf::Font Game::regular;
sf::View Game::_view;

bool Game::_editingBuilding;
bool Game::_screenLocked;
Building* Game::_currentBuilding;