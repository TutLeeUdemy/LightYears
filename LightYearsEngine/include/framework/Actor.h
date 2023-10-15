#pragma once
#include <SFML/Graphics.hpp>

#include "framework/Core.h"
#include "framework/Object.h"
class b2Body;

namespace ly
{
	class World;
	class Actor : public Object
	{
	public:
		Actor(World* owningWorld, const std::string& texturePath = "");
		virtual ~Actor();
		void BeginPlayInternal();
		void TickInternal(float deltaTime);
		virtual void BeginPlay();
		virtual void Tick(float deltaTime);
		void SetTexture(const std::string& texturePath);
		void Render(sf::RenderWindow& window);

		void SetActorLocation(const sf::Vector2f& newLoc);
		void SetActorRotation(float newRot);
		void AddActorLocationOffset(const sf::Vector2f& offsetAmt);
		void AddActorRotationOffset(float offsetAmt);

		sf::Vector2f GetActorLocation() const;
		float GetActorRotation() const;
		sf::Vector2f GetActorForwardDirection() const;
		sf::Vector2f GetActorRightDirection() const;
		sf::FloatRect GetActorGlobalBounds() const;

		sf::Vector2u GetWindowSize() const;

		World* GetWorld() const { return mOwningWorld; }

		bool IsActorOutOfWindowBounds() const;

		void SetEnablePhysics(bool enable);
		virtual void OnActorBeginOverlap(Actor* other);
		virtual void OnActorEndOverlap(Actor* other);
	private:
		void InitiallizePhyics();
		void UnInitializePhysics();
		void UpdatePhysicsBodyTransform();
		void CenterPivot();
		
		World* mOwningWorld;
		bool mHasBeganPlay;

		sf::Sprite mSprite;
		shared<sf::Texture> mTexture;
		
		b2Body* mPhysicBody;
		bool mPhysicsEnabled;
	};
}