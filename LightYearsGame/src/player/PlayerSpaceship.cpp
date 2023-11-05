#include "player/PlayerSpaceship.h"
#include "SFML/System.hpp"
#include "framework/MathUtility.h"
#include "weapon/BulletShooter.h"
#include "weapon/ThreeWayShooter.h"
#include "weapon/FrontalWiper.h"

namespace ly
{
	PlayerSpaceship::PlayerSpaceship(World* owningWorld, const std::string& path)
		: Spaceship{owningWorld, path},
		mMoveInput{},
		mSpeed{200.f},
		mShooter{ new BulletShooter{this, .5f, {50.f, 0.f}} },
		mInvulnerableTime{2.f},
		mInvulnerable{true},
		mInvulnerableFlashInterval{0.5f},
		mInvulnerableFlashTimer{0.f},
		mInvulerableFlashDir{1}
	{
		SetTeamID(1);
		mShooter->SetCurrentLevel(4);
	}

	void PlayerSpaceship::Tick(float deltaTime)
	{
		Spaceship::Tick(deltaTime);
		HandleInput();
		ConsumeInput(deltaTime);
		UpdateInvulnerable(deltaTime);
	}

	void PlayerSpaceship::Shoot()
	{
		if (mShooter)
		{
			mShooter->Shoot();
		}
	}

	void PlayerSpaceship::SetShooter(unique<Shooter>&& newsShooter)
	{
		if (mShooter && typeid(*mShooter.get()) == typeid(*newsShooter.get()))
		{
			mShooter->IncrementLevel();
			return;
		}

		mShooter = std::move(newsShooter);
	}

	void PlayerSpaceship::ApplyDamage(float amt)
	{
		if (!mInvulnerable)
		{
			Spaceship::ApplyDamage(amt);
		}
	}

	void PlayerSpaceship::BeginPlay()
	{
		Spaceship::BeginPlay();
		TimerManager::Get().SetTimer(GetWeakRef(), &PlayerSpaceship::StopInvulnerable, mInvulnerableTime);
	}

	void PlayerSpaceship::HandleInput()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			mMoveInput.y = -1.f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			mMoveInput.y = 1.f;
		}
		 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			mMoveInput.x = -1.f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			mMoveInput.x = 1.f;
		}

		ClampInputOnEdge();
		NormalizeInput();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			Shoot();
		}
	}
	void PlayerSpaceship::NormalizeInput()
	{
		Normalize(mMoveInput);
	}
	void PlayerSpaceship::ClampInputOnEdge()
	{
		sf::Vector2f actorLocation = GetActorLocation();
		if (actorLocation.x < 0 && mMoveInput.x == -1)
		{
			mMoveInput.x = 0.f;
		}

		if (actorLocation.x > GetWindowSize().x && mMoveInput.x == 1.f)
		{
			mMoveInput.x = 0.f;
		}

		if (actorLocation.y < 0 && mMoveInput.y == -1)
		{
			mMoveInput.y = 0.f;
		}

		if (actorLocation.y > GetWindowSize().y && mMoveInput.y == 1.f)
		{
			mMoveInput.y = 0.f;
		}
	}
	void PlayerSpaceship::ConsumeInput(float deltaTime)
	{
		SetVelocity(mMoveInput * mSpeed);
		mMoveInput.x = mMoveInput.y = 0.f;
	}

	void PlayerSpaceship::StopInvulnerable()
	{
		GetSprite().setColor({255,255,255,255});
		mInvulnerable = false;
	}

	void PlayerSpaceship::UpdateInvulnerable(float deltaTime)
	{
		if (!mInvulnerable) return;
		
		mInvulnerableFlashTimer += deltaTime * mInvulerableFlashDir;
		if (mInvulnerableFlashTimer < 0 || mInvulnerableFlashTimer > mInvulnerableFlashInterval)
		{
			mInvulerableFlashDir *= -1;
		}

		GetSprite().setColor(LerpColor({255,255, 255, 64} ,{255, 255, 255, 128}, mInvulnerableFlashTimer/mInvulnerableFlashInterval));
	}
}