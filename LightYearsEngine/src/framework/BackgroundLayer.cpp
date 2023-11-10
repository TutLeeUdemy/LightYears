#include "framework/BackgroundLayer.h"
#include "framework/AssetManager.h"
#include "framework/MathUtility.h"
namespace ly
{
	BackgroundLayer::BackgroundLayer(World* ownningWorld, 
		const List<std::string>& assetPaths,
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
		SetAssets(assetPaths);
		SetEnablePhysics(false);
	}

	void BackgroundLayer::SetAssets(const List<std::string>& assetPaths)
	{
		for (const std::string& texturePath : assetPaths)
		{
			shared<sf::Texture> newTexture = AssetManager::Get().LoadTexture(texturePath);
			mTextures.push_back(newTexture);
		}
	}

	void BackgroundLayer::RefreshSprites()
	{
		mSprites.clear();
		mVelocities.clear();

		for (int i = 0; i < mSpriteCount; ++i)
		{
			sf::Sprite newSprite{};
			RandomSpriteTexture(newSprite);
		}
	}

	void BackgroundLayer::RandomSpriteTexture(sf::Sprite& sprite)
	{
		if (mTextures.size() > 0)
		{
			shared<sf::Texture> pickedTexture = GetRandomTexture();
			sprite.setTexture(*(pickedTexture.get()));
			sprite.setTextureRect(sf::IntRect{ 0,0,pickedTexture->getSize().x, pickedTexture->getSize().y });
			sf::FloatRect bound = sprite.getGlobalBounds();
			sprite.setOrigin(bound.width/2.f, bound.height/2.f);
		}
	}
	shared<sf::Texture> BackgroundLayer::GetRandomTexture() const
	{
		int randomPickIndex = (int)(RandomRange(0, mTextures.size()));
		return mTextures[randomPickIndex];
	}
}