#pragma once
#include <SFML/Graphics.hpp>

#include "framework/Core.h"
#include "framework/Object.h"

namespace ly
{
	class Actor;
	class HUD;
	class Application;
	class GameStage;

	class World : public Object
	{
	public:
		World(Application* owningApp);
		
		void BeginPlayInternal();
		void TickInternal(float deltaTime);
		void Render(sf::RenderWindow& window);

		virtual ~World();

		template<typename ActorType, typename... Args>
		weak<ActorType> SpawnActor(Args... args);

		template<typename HUDType, typename... Args>
		weak<HUDType> SpawnHUD(Args... args);

		sf::Vector2u GetWindowSize() const;
		void CleanCycle();
		void AddStage(const shared<GameStage>& newStage);
		bool DispathEvent(const sf::Event& event);
		Application* GetApplication() { return mOwningApp; }
		const Application* GetApplication() const { return mOwningApp; }
	private:
		virtual void BeginPlay();
		virtual void Tick(float deltaTime);
		void RenderHUD(sf::RenderWindow& window);
		Application* mOwningApp;
		bool mBeganPlay;

		List<shared<Actor>> mActors;

		List<shared<Actor>> mPendingActors;

		List<shared<GameStage>> mGameStages;
		
		List<shared<GameStage>>::iterator mCurrentStage;

		shared<HUD> mHUD;

		virtual void InitGameStages();
		virtual void AllGameStageFinished();
		void NextGameStage();
		void StartStages();
	};


	template<typename ActorType, typename... Args>
	weak<ActorType> World::SpawnActor(Args... args)
	{
		shared<ActorType> newActor{ new ActorType(this, args...) };
		mPendingActors.push_back(newActor);
		return newActor;
	}

	template<typename HUDType, typename ...Args>
	inline weak<HUDType> World::SpawnHUD(Args ...args)
	{
		shared<HUDType> newHUD{ new HUDType(args...)};
		mHUD = newHUD;
		return newHUD;
	}

}