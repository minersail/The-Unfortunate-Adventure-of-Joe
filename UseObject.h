#pragma once
#include "stdafx.h"
#include "Entity.h"

/*
Base class for any class that the player can face and press space to interact with
*/
class UseObject : public Entity
{
public:
	struct UsePoint
	{
		int x;
		int y;
		Direction dir;

		// X and Y values are using the 16x16 coordinate system, not pixels
		UsePoint(int X, int Y,Direction Dir)
		{
			dir = Dir;
			x = X;
			y = Y;
		}
	};

	UseObject(float initX, float initY, std::string textureID, std::string name, sf::IntRect hitbox);
	~UseObject();


	// Returns true if the player is overlapping one of the UsePoints with the correct direction
	bool CheckUsePoints(sf::Event ev);

protected:
	std::vector<UsePoint> activationLocs;
};