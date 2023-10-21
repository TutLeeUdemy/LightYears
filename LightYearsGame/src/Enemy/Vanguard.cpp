#include "Enemy/Vanguard.h"
#include "weapon/BulletShooter.h"
namespace ly
{
	Vangaurd::Vangaurd(World* owningWorld, const std::string& texturePath, const sf::Vector2f& velocity)
		: EnemySpaceship{ owningWorld, texturePath },
		mShooter{ new BulletShooter{this} }
	{
		SetVelocity(velocity);
		SetActorRotation(90.f);
	}

	void Vangaurd::Tick(float deltaTime)
	{
		EnemySpaceship::Tick(deltaTime);
		Shoot();
	}

	void Vangaurd::Shoot()
	{
		mShooter->Shoot();
	}

}