#include "stdafx.h"
#include "Building.h"
#include "Game.h"

Building::Building(float initX, float initY, std::string textureID, std::string name, UsePoint entrance, UsePoint exit)
	: UseObject(initX, initY, textureID, name, entrance), exitPoint(exit)
{
	immovable = true;
}

Building::~Building()
{
}

void Building::Update(float deltaTime, sf::Event ev)
{
	if (CheckUsePoints(ev))
	{
		Game::SetView(-400, 400);
		Game::LockView(true);
		floorManager.Add("Joe", Game::GetJoe());
		Game::GetJoe()->SetPosition(exitPoint.x * 16 - 800, exitPoint.y * 16);

		while (true)
		{
			sf::Event currentEvent;
			Game::GetWindow().pollEvent(currentEvent);
			Game::GetWindow().clear(sf::Color::Black);

			Game::GetCollisionManager().CheckChunkCollisions(-1);

			floorManager.UpdateAll(currentEvent);
			floorManager.DrawAll(Game::GetWindow());
			Game::GetWindow().display();

			//Game::GetWindow().display();

			if (currentEvent.type == sf::Event::Closed)
			{
				Game::_gameState = Game::Exiting;
			}

			if (currentEvent.type == sf::Event::KeyPressed && currentEvent.key.code == sf::Keyboard::Space)
			{
				float pX = Game::GetJoe()->GetPosition().x + Game::GetJoe()->GetHitBox().left;
				float pY = Game::GetJoe()->GetPosition().y + Game::GetJoe()->GetHitBox().top;

				sf::RectangleShape unit;
				unit.setSize(sf::Vector2f(16, 16));
				unit.setPosition(exitPoint.x * 16 - 800, exitPoint.y * 16 - 8); // Adjust the UsePoints by half a unit

				unit.setFillColor(sf::Color::Red);
				Game::GetWindow().draw(unit);
				Game::GetWindow().display();

				if (unit.getGlobalBounds().contains(pX, pY))
				{
					sf::IntRect joeRect = Game::GetJoe()->GetTextureRect();
					if ((joeRect.left == joeRect.width * 0 && exitPoint.dir == Up) || (joeRect.left == joeRect.width * 1 && exitPoint.dir == Right)
						|| (joeRect.left == joeRect.width * 2 && exitPoint.dir == Down) || (joeRect.left == joeRect.width * 3 && exitPoint.dir == Left))
					{
						Game::LockView(false);
						Game::GetJoe()->SetPosition(activationLocs[0].x * 16, activationLocs[0].y * 16);
						return;
					}
				}
			}
		}
	}
}

void Building::SetFloorManager(GameObjectManager& objMnger)
{
	floorManager = objMnger;
}