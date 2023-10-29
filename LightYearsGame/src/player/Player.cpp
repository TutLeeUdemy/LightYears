#include "player/Player.h"
#include "framework/World.h"
#include "player/PlayerSpaceship.h"
namespace ly
{
	Player::Player()
		: mLifeCount{3},
		mScore{0},
		mCurrentPlayerSpaceship{}
	{
	}
	weak<PlayerSpaceship> Player::SpawnSpaceship(World* world)
	{
		if (mLifeCount > 0)
		{
			--mLifeCount;
			auto windowSize = world->GetWindowSize();
			mCurrentPlayerSpaceship = world->SpawnActor<PlayerSpaceship>();
			mCurrentPlayerSpaceship.lock()->SetActorLocation(sf::Vector2f(windowSize.x/2.f, windowSize.y - 100.f));
			mCurrentPlayerSpaceship.lock()->SetActorRotation(-90.f);
			onLifeChange.Broadcast(mLifeCount);
		}
		else
		{
			onLifeExhausted.Broadcast();
		}
	}

	void Player::AddLifeCount(unsigned int count)
	{
		if (count > 0)
		{
			mLifeCount += count;
			onLifeChange.Broadcast(mLifeCount);
		}
	}
	int Player::AddScore(unsigned int amt)
	{
		if (amt > 0)
		{
			mScore == amt;
			onScoreChange.Broadcast(mScore);
		}
	}
}