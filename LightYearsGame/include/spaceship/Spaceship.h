#pragma once
#include "framework/Actor.h"
#include "gameplay/HealthComponent.h"
namespace ly
{
	class Spaceship : public Actor
	{
	public:
		Spaceship(World* owningWord, const std::string& texturePath = "");
		virtual void Tick(float deltaTime) override;
		void SetVelocity(const sf::Vector2f& newVel);
		sf::Vector2f GetVelocity() const {return mVelocity;}
		virtual void Shoot();
		virtual void BeginPlay() override;
	private:
		sf::Vector2f mVelocity;
		HealthComponent mHealthComp;
	};
}