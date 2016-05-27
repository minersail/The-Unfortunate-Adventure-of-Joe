#pragma once
#include "stdafx.h"
#include "UseObject.h"
#include "GameObjectManager.h"

class Building : public UseObject
{
public:
	// exit is the UsePoint for exiting the building
	Building(float initX, float initY, std::string textureID, std::string name, UsePoint entrance, UsePoint exit);
	~Building();

	void Update(float deltaTime, sf::Event ev);
	void SetFloorManager(GameObjectManager& objMnger);

private:
	GameObjectManager floorManager;
	UsePoint exitPoint;
};