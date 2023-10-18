#pragma once

#include "framework/Actor.h"

namespace ly
{
	class Bullet : public Actor
	{
	public:
		Bullet(World* world, Actor* owner, const std::string& texturePath, float speed = 600.f, float damage = 10.f);
	
		void SetSpeed(float newSpeed);
		void SetDamage(float newDaamge);
		float GetDamage() const { return mDamage; }
		virtual void Tick(float deltaTime) override;
		virtual void BeginPlay() override;
	private:

		virtual void OnActorBeginOverlap(Actor* other) override;
		void Move(float deltaTime);
		Actor* mOwner;
		float mSpeed;
		float mDamage;
	};
}