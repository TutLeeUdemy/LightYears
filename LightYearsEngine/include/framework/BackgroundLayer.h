#pragma once

#include "framework/Actor.h"

namespace ly
{
	class BackgroundLayer : public Actor
	{
	public:
		BackgroundLayer(World* ownningWorld,
			const List<std::string>& assetpaths = {},
			const sf::Vector2f& minVel = sf::Vector2f{0.f, 50.f},
			const sf::Vector2f& maxVel = sf::Vector2f{0.f, 200.f},
			float sizeMin = 1.f,
			float sizeMax = 2.f,
			int spriteCount = 20,
			const sf::Color& colorTint = sf::Color{180, 180, 200, 225}
		);
	
	private:
		sf::Vector2f mMinVelocity;
		sf::Vector2f mMaxVelocity;
		float mSizeMin;
		float mSizeMax;
		int mSpriteCount;
		sf::Color mTintColor;

		List<shared<sf::Texture>> mTextures;
		List<sf::Sprite> mSprites;
		List<sf::Vector2f> mVelocities;
	};
}