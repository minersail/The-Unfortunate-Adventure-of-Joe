#include "stdafx.h"
#include "Player.h"
#include "Game.h"
//#include "Block.h"
//#include "NPC.h"

Player::Player(float initX, float initY, std::string textureID, std::string name)
	: Entity(initX, initY, textureID, name, sf::IntRect(0, JOE_HEIGHT / 3, JOE_WIDTH, JOE_HEIGHT / 2))
{
	SetTextureRect(0, 0, JOE_HEIGHT, JOE_WIDTH);
	GetSprite().setOrigin(JOE_WIDTH / 2, JOE_HEIGHT / 2);

	keyPressed = None;
	frameCount = 0;
}

Player::~Player()
{
}

void Player::Update(float deltaTime, sf::Event ev)
{
	UpdateChunk();

	if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::W)
	{
		keyPressed = Up;
	}
	if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::A)
	{
		keyPressed = Left;
	}
	if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::S)
	{
		keyPressed = Down;
	}
	if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::D)
	{
		keyPressed = Right;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (keyPressed == None || keyPressed == Up)
		{
			Walk(Up);
			keyPressed = Up;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (keyPressed == None || keyPressed == Down)
		{
			Walk(Down);
			keyPressed = Down;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (keyPressed == None || keyPressed == Left)
		{
			Walk(Left);
			keyPressed = Left;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (keyPressed == None || keyPressed == Right)
		{
			Walk(Right);
			keyPressed = Right;
		}
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		Walk(None);
		keyPressed = None;
	}

	if (collided)
	{
		collided = false;
	}

	Game::SetView(std::max(float(Game::SCREEN_WIDTH / 2), std::min(float(Game::SCREEN_WIDTH * Game::XCHUNKS - Game::SCREEN_WIDTH / 2), GetPosition().x)), 
				  std::max(float(Game::SCREEN_HEIGHT / 2), std::min(float(Game::SCREEN_HEIGHT * Game::YCHUNKS - Game::SCREEN_HEIGHT / 2), GetPosition().y)));
}

void Player::Walk(Player::Direction _direction)
{
	frameCount += 1;
	switch (_direction)
	{
		case Up:
		{
			SetTextureRect(0, GetSprite().getTextureRect().top, JOE_WIDTH, JOE_HEIGHT);
			SetPosition(GetPosition().x, GetPosition().y - 3);
			break;
		}
		case Down:
		{
			SetTextureRect(34, GetSprite().getTextureRect().top, JOE_WIDTH, JOE_HEIGHT);
			SetPosition(GetPosition().x, GetPosition().y + 3);
			break;
		}
		case Left:
		{
			SetTextureRect(51, GetSprite().getTextureRect().top, JOE_WIDTH, JOE_HEIGHT);
			SetPosition(GetPosition().x - 3, GetPosition().y);
			break;
		}
		case Right:
		{
			SetTextureRect(17, GetSprite().getTextureRect().top, JOE_WIDTH, JOE_HEIGHT);
			SetPosition(GetPosition().x + 3, GetPosition().y);
			break;
		}
		case None:
		{
			SetTextureRect(GetSprite().getTextureRect().left, 0, JOE_WIDTH, JOE_HEIGHT);
			return;
			break;
		}
	}

	if (frameCount % 10 == 0)
	{
		if (GetSprite().getTextureRect().top != 78)
		{
			SetTextureRect(GetSprite().getTextureRect().left, GetSprite().getTextureRect().top + JOE_HEIGHT, JOE_WIDTH, JOE_HEIGHT);
		}
		else
		{
			SetTextureRect(GetSprite().getTextureRect().left, 0, JOE_WIDTH, JOE_HEIGHT);
		}
	}
}

void Player::UpdateChunk() // CHANGE WHEN THERE ARE MORE THAN 9 CHUNKS
{
	// Offset to top-left corner of player's hitbox
	int newChunk = std::floor((GetPosition().x + GetHitBox().width / 2) / Game::SCREEN_WIDTH) + std::floor((GetPosition().y + GetHitBox().height / 2) / Game::SCREEN_HEIGHT) * Game::YCHUNKS;
	if (newChunk != ChunkID) // There has been a change in chunk
	{
		if (newChunk < ChunkID - 1) // Up
		{
			std::cout << "Up" << std::endl;
		}
		else if (newChunk < ChunkID) // Left
		{
			std::cout << "Left" << std::endl;
		}
		else if(newChunk > ChunkID + 1) // Down
		{
			std::cout << "Down" << std::endl;
		}
		else if (newChunk > ChunkID) // Right
		{
			std::cout << "Right" << std::endl;
		}
		Game::GetCollisionManager().Remove(ChunkID, this);
		ChunkID = newChunk;
		Game::GetCollisionManager().Add(ChunkID, this);
	}
}

void Player::Draw(sf::RenderWindow& rw)
{
	rw.draw(GetSprite());
	/*sf::RectangleShape hitbox;
	hitbox.setSize(sf::Vector2f(GetHitBox().width, GetHitBox().height));
	hitbox.setOutlineColor(sf::Color::Red);
	hitbox.setFillColor(sf::Color(255, 255, 255, 0));
	hitbox.setOutlineThickness(2);
	hitbox.setOrigin(GetHitBox().width / 2, GetHitBox().height / 2);
	hitbox.setPosition(GetPosition().x, GetPosition().y);
	hitbox.setPosition(GetPosition().x + GetHitBox().left / 2, GetPosition().y + GetHitBox().top / 2);
	rw.draw(hitbox);*/
}