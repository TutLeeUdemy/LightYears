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
		mHealthComp.onHealthChanged.BindAction(GetWeakRef(), &Spaceship::OnHealthChanged);
		mHealthComp.onTakenDamage.BindAction(GetWeakRef(), &Spaceship::OnTakenDamage);
		mHealthComp.onHealthEmpty.BindAction(GetWeakRef(), &Spaceship::Blow);
	}
	void Spaceship::ApplyDamage(float amt)
	{
		mHealthComp.ChangeHealth(-amt);
	}

	void Spaceship::OnHealthChanged(float amt, float health, float maxHealth)
	{

	}

	void Spaceship::OnTakenDamage(float amt, float health, float maxHealth)
	{

	}

	void Spaceship::Blow()
	{
		Destory();
	}
}