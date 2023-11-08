#include "framework/BackgroundLayer.h"

namespace ly
{
	BackgroundLayer::BackgroundLayer(World* ownningWorld, 
		const List<std::string>& assetpaths, 
		const sf::Vector2f& minVel,
		const sf::Vector2f& maxVel,
		float sizeMin, 
		float sizeMax, 
		int spriteCount,
		const sf::Color& colorTint)
		: Actor{ownningWorld},
		mMinVelocity{minVel},
		mMaxVelocity{maxVel},
		mSizeMin{sizeMin},
		mSizeMax{sizeMax},
		mSpriteCount{spriteCount},
		mTintColor{colorTint}
	{
		SetEnablePhysics(false);
	}
}