#pragma once
#include "framework/Actor.h"
namespace ly
{
	class BackdropActor : public Actor
	{
	public:
		BackdropActor(World* owningWorld, const std::string& texturePath, const sf::Vector2f& velocity = sf::Vector2f{0.f, -50.f});
		virtual void Tick(float deltaTime) override;
	private:
		sf::Vector2f mMovingVelocity;
		float mLeftShift;
		float mTopShift;
	};
}