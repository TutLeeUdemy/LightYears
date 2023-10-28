#pragma once
#include <SFML/Graphics.hpp>
#include "Weapon/BulletShooter.h"

namespace ly
{
	class FrontalWiper : public Shooter
	{
	public:
		FrontalWiper(Actor* ownerActor, 
			float cooldownTime = 0.3f,
			const sf::Vector2f& localOffset = { 0.f, 0.f },
			float width = 60.f
		);
		
	private:
		virtual void ShootImpl() override;

		float mWidth;

		BulletShooter mShooter1;
		BulletShooter mShooter2;
		BulletShooter mShooter3;
		BulletShooter mShooter4;
	};
}