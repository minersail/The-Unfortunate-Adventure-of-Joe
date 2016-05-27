#pragma once
#include "stdafx.h"
#include "GameObjectManager.h"
#include "ResourceManager.h"
#include "CollisionManager.h"
#include "DialogueManager.h"
#include "Player.h"

class Game {
public:
	static void Start();
	static sf::RenderWindow& GetWindow(); // Returns game window
	static GameObjectManager& GetObjectManager(); // Returns the current GameObjectMananger
	static ResourceManager& GetResourceManager(); // Returns _resourceManager
	static CollisionManager& GetCollisionManager(); // Returns _collisionManager
	static DialogueManager& GetDialogueManager(); // Returns _dialogueManager

	static sf::Font& GetFont(std::string fontID);
	static Player* GetJoe(); // Returns Joe
	// Short for GetTextureSize(); Intentionally short name for use in constructors before the texture is loaded
	static sf::Vector2i GTS(std::string textureID);

	static void SetView(float newX, float newY);
	static void LockView(bool lock);
	static void SwitchObjectManager(bool toMain);

	const static int SCREEN_HEIGHT = 800;
	const static int SCREEN_WIDTH = 800;
	const static int YCHUNKS = 3;
	const static int XCHUNKS = 3;

	enum GameState {
		Uninitialized, Paused, Talking,
		ShowingWorld, Playing, Exiting, GameOver
	};

	static GameState _gameState; // Current GameState

private:
	static bool IsExiting(); // Checks if exit event has been called
	static void GameLoop(); // Main game function
	static void LoadFonts(); // Load font(s)

	static sf::Font regular;

	static sf::RenderWindow _mainWindow; // main window. duh
	static sf::View _view;
	static GameObjectManager _gameObjectManager; // Main GameObjectManager
	static GameObjectManager _buildingObjectMananger; // GameObjectManager for the current Building
	static ResourceManager _resourceManager; // ResourceManager
	static CollisionManager _collisionManager; // CollisionManager
	static DialogueManager _dialogueManager; // DialogueManager

	static bool _editingBuilding;
	static bool _screenLocked;
};