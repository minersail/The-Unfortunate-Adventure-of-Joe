#pragma once
#include "stdafx.h"
#include "Barrier.h"
#include "Game.h"

Barrier::Barrier(float initX, float initY, std::string textureID, std::string name, int animationFrames)
	: Entity(initX, initY, textureID, name, sf::IntRect(0, 0, Game::GetResourceManager().Get(textureID).getSize().x / animationFrames, Game::GetResourceManager().Get(textureID).getSize().y)),
	tiled(false), maxFrame(animationFrames), currentFrame(1), tiledSize(sf::Vector2f(0, 0))
{
	immovable = true;
	Animate();
}

Barrier::Barrier(float initX, float initY, std::string textureID, std::string name, sf::Vector2i size, int animationFrames)
	: Entity(initX, initY, textureID, name, sf::IntRect(0, 0, size.x * 16, size.y * 16)),
	tiled(true), maxFrame(animationFrames), currentFrame(1), tiledSize(size)
{
	// Resize VerticeList to size of Barrier
	VerticeList.setPrimitiveType(sf::Quads);
	VerticeList.resize(tiledSize.x * tiledSize.y * 4);

	Animate();

	immovable = true;
}

Barrier::~Barrier()
{
}

void Barrier::Update(float deltaTime, sf::Event ev)
{
	frameCount++;

	if (frameCount % 30 == 0)
	{
		Animate();
	}
}

void Barrier::Animate()
{
	currentFrame++;
	if (currentFrame > maxFrame)
	{
		currentFrame = 1;
	}

	if (tiled) // Barrier type 4
	{
		// Manually repeat the texture
		// sf::Texture.setRepeated() will not work because it is dependant on using large textureRects, and that interferes with animation
		for (int i = 0; i < tiledSize.x; ++i)
		{
			for (int j = 0; j < tiledSize.y; ++j)
			{
				// get a pointer to the current tile's quad
				sf::Vertex* quad = &VerticeList[(i + j * tiledSize.y) * 4];

				// define its 4 corners
				// We subtract GetHitBox().width and height in order for GetPosition() to return the center
				quad[0].position = sf::Vector2f(GetPosition().x - GetHitBox().width / 2 + i * 16, GetPosition().y - GetHitBox().height / 2 + j * 16);
				quad[1].position = sf::Vector2f(GetPosition().x - GetHitBox().width / 2 + (i + 1) * 16, GetPosition().y - GetHitBox().height / 2 + j * 16);
				quad[2].position = sf::Vector2f(GetPosition().x - GetHitBox().width / 2 + (i + 1) * 16, GetPosition().y - GetHitBox().height / 2 + (j + 1) * 16);
				quad[3].position = sf::Vector2f(GetPosition().x - GetHitBox().width / 2 + i * 16, GetPosition().y - GetHitBox().height / 2 + (j + 1) * 16);

				// define its 4 texture coordinates
				// With animated barriers the textures should be in a straight, horizontal line, so y values do not change
				// Frames are 1-indexed, but the textures are 0-indexed, hence the (currentFrame - 1)
				quad[0].texCoords = sf::Vector2f((currentFrame - 1) * 16, 0);
				quad[1].texCoords = sf::Vector2f((currentFrame) * 16, 0);
				quad[2].texCoords = sf::Vector2f((currentFrame) * 16, 16);
				quad[3].texCoords = sf::Vector2f((currentFrame - 1) * 16, 16);
			}
		}
	}
	else // Barrier type 2
	{
		// Size of one frame
		sf::Vector2i frameSize(GetSprite().getTexture()->getSize().x / maxFrame, GetSprite().getTexture()->getSize().y);
		SetTextureRect(frameSize.x * (currentFrame - 1), 0, GetHitBox().width, GetHitBox().height);
	}
}

void Barrier::Draw(sf::RenderWindow& rw)
{
	if (tiled)
	{
		rw.draw(VerticeList, GetSprite().getTexture());
	}
	else
	{
		rw.draw(GetSprite());
	}
};