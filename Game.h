#pragma once
#include "stdafx.h"
#include "GameObjectManager.h"
#include "ResourceManager.h"
#include "CollisionManager.h"

class Game {
public:
	static void Start();
	static sf::RenderWindow& GetWindow(); // Returns game window
	static GameObjectManager& GetObjectManager(); // Returns _gameObjectManager
	static ResourceManager& GetResourceManager(); // Returns _resourceManager
	static CollisionManager& GetCollisionManager(); // Returns _collisionManager
	// Enter an object into the gameobjectmanager and set its position
	static void Initialize(std::string name, VisibleGameObject* obj, float x, float y);
	static void SetView(float newX, float newY);

	const static int SCREEN_HEIGHT = 800;
	const static int SCREEN_WIDTH = 800;
	const static int YCHUNKS = 3;
	const static int XCHUNKS = 3;

	static sf::Font regular;

	enum GameState {
		Uninitialized, Paused, Talking,
		ShowingWorld, Playing, Exiting, GameOver
	};

	static GameState _gameState; // Current GameState

private:
	static bool IsExiting(); // Checks if exit event has been called
	static void GameLoop(); // Main game function
	static void LoadFonts(); // Load font(s)

	static sf::RenderWindow _mainWindow; // main window. duh
	static sf::View _view;
	static GameObjectManager _gameObjectManager; // GameObjectManager
	static ResourceManager _resourceManager; // ResourceManager
	static CollisionManager _collisionManager; // CollisionManager
};