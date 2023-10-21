#pragma once
#include <SFML/Graphics.hpp>

#include "framework/Core.h"
#include "framework/Object.h"

namespace ly
{
	class Actor;
	class Application;
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

		sf::Vector2u GetWindowSize() const;
		void CleanCycle();
	private:
		virtual void BeginPlay();
		virtual void Tick(float deltaTime);
		Application* mOwningApp;
		bool mBeganPlay;

		List<shared<Actor>> mActors;

		List<shared<Actor>> mPendingActors;
	};


	template<typename ActorType, typename... Args>
	weak<ActorType> World::SpawnActor(Args... args)
	{
		shared<ActorType> newActor{ new ActorType(this, args...) };
		mPendingActors.push_back(newActor);
		return newActor;
	}

}