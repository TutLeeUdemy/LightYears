#include <box2D/b2_body.h>
#include <box2D/b2_fixture.h>
#include <box2D/b2_polygon_shape.h>

#include "framework/PhysicsSystem.h"
#include "framework/Actor.h"
#include "framework/MathUtility.h"
namespace ly
{
	unique<PhysicsSystem> PhysicsSystem::physicsSystem{ nullptr };

	PhysicsSystem& PhysicsSystem::Get()
	{
		if (!physicsSystem)
		{
			physicsSystem = std::move(unique<PhysicsSystem>{new PhysicsSystem});
		}

		return *physicsSystem;
	}

	void PhysicsSystem::Step(float deltaTime)
	{
		mPhysicsWorld.Step(deltaTime, mVelocityIterations, mPositionIterations);
	}

	b2Body* PhysicsSystem::AddListener(Actor* listener)
	{
		if (listener->IsPendingDestory()) return nullptr;

		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;

		bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(listener);
		
		bodyDef.position.Set(listener->GetActorLocation().x * GetPhysicsScale(), listener->GetActorLocation().y * GetPhysicsScale());
		bodyDef.angle = DegreesToRadians(listener->GetActorRotation());

		b2Body* body = mPhysicsWorld.CreateBody(&bodyDef);

		b2PolygonShape shape;
		auto bound = listener->GetActorGlobalBounds();
		shape.SetAsBox(bound.width/2.f * GetPhysicsScale(), bound.height / 2.f * GetPhysicsScale());

		b2FixtureDef fixtureDef;
		fixtureDef.shape = &shape;
		fixtureDef.density = 1.0f;
		fixtureDef.friction = 0.3f;
		fixtureDef.isSensor = true;

		body->CreateFixture(&fixtureDef);

		return body;
	}

	PhysicsSystem::PhysicsSystem()
		: mPhysicsWorld{ b2Vec2{0.f,0.f} },
		mPhysicsScale{0.01f},
		mVelocityIterations{8},
		mPositionIterations{3}
	{

	}
}