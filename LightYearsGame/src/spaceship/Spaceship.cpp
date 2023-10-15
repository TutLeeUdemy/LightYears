#include "spaceship/Spaceship.h"

namespace ly
{
	Spaceship::Spaceship(World* owningWord, const std::string& texturePath)
		: Actor{ owningWord, texturePath },
		mVelocity{},
		mHealthComp{100.f, 100.f}
	{

	}


	void Spaceship::Tick(float deltaTime)
	{
		Actor::Tick(deltaTime);
		AddActorLocationOffset(GetVelocity() * deltaTime);
	}

	void Spaceship::SetVelocity(const sf::Vector2f& newVel)
	{
		mVelocity = newVel;
	}

	void Spaceship::Shoot()
	{

	}

	void Spaceship::BeginPlay()
	{
		Actor::BeginPlay();
		SetEnablePhysics(true);
	}
}