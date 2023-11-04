#pragma once
#include "spaceship/Spaceship.h"
#include "framework/TimerManager.h"
namespace ly
{
	class Shooter;
	class PlayerSpaceship : public Spaceship
	{
	public:
		PlayerSpaceship(World* owningWorld, const std::string& path = "SpaceShooterRedux/PNG/playerShip1_blue.png");
	
		virtual void Tick(float deltaTime) override;
		void SetSpeed(float newSpeed) { mSpeed = newSpeed; }
		float GetSpeed() const { return mSpeed; }
		virtual void Shoot() override;
		void SetShooter(unique<Shooter>&& newsShooter);
		virtual void ApplyDamage(float amt) override;
		virtual void BeginPlay() override;
	private:
		void HandleInput();
		void NormalizeInput();
		void ClampInputOnEdge();
		void ConsumeInput(float deltaTime);
		void StopInvulnerable();
		void UpdateInvulnerable(float deltaTime);
		sf::Vector2f mMoveInput;
		float mSpeed;

		unique<Shooter> mShooter;
	
		float mInvulnerableTime;
		TimerHandle mInvulerableTimerHandle;
		bool mInvulnerable;

		float mInvulnerableFlashInterval;
		float mInvulnerableFlashTimer;
		float mInvulerableFlashDir;
	};
}