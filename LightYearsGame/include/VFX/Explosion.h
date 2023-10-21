#pragma once
#include <string>
#include "framework/Core.h"

namespace ly
{
	class World;
	class Explosion
	{
	public:
		Explosion(int particleAmt = 20,
			float lifeTimeMin = 0.5f,
			float lifeTimeMax = 1.5f,
			float sizeMin = 1,
			float sizeMax = 3,
			float speedMin = 200,
			float speedMax = 400,
			const sf::Color& particleColor = sf::Color{ 255, 128,0, 255 },
			const List<std::string>& particleImagePaths = 
			{
				"SpaceShooterRedux/PNG/Effects/star1.png",
				"SpaceShooterRedux/PNG/Effects/star2.png",
				"SpaceShooterRedux/PNG/Effects/star3.png"
			}
		);

		void SpawnExplosion(World* world, const sf::Vector2f& location);

	private:
		int mParticleAmt;
		float mLifeTimeMin;
		float mLifeTimeMax;
		float mSizeMin;
		float mSizeMax;
		float mSpeedMin;
		float mSpeedMax;
		sf::Color mParticleColor;

		List<std::string> mParticleImagePaths;
	};
}