#pragma once
#include "Enemy/EnemySpaceship.h"
namespace ly
{
	class BulletShooter;
	class Vangaurd : public EnemySpaceship
	{
	public:
		Vangaurd(World* owningWorld, const std::string& texturePath = "SpaceShooterRedux/PNG/Enemies/enemyBlue3.png", const sf::Vector2f& velocity = {0.f, 50.f});
		virtual void Tick(float deltaTime) override;
	private:
		virtual void Shoot() override;
		unique<BulletShooter> mShooter;
	};
}