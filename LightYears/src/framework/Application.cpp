#include <iostream>
#include "framework/Application.h"
namespace ly
{
	Application::Application()
		: mWindow{ sf::VideoMode(1024, 1440), "Light Years" },
		mTargetFrameRate{30.f},
		mTickClock{}
	{
		
	}

	void Application::Run()
	{
		mTickClock.restart();
		float accumulatedTime = 0.f;
		float targetDeltaTime = 1.f / mTargetFrameRate;
		while (mWindow.isOpen())
		{
			sf::Event windowEvent;
			while (mWindow.pollEvent(windowEvent))
			{
				if (windowEvent.type == sf::Event::EventType::Closed)
				{
					mWindow.close();
				}
			}
			float frameDeltaTime = mTickClock.restart().asSeconds();
			accumulatedTime += frameDeltaTime;
			while (accumulatedTime > targetDeltaTime)
			{
				accumulatedTime -= targetDeltaTime;
				Tick(targetDeltaTime);
				Render();
			}
			std::cout << "ticking at framerate: " << 1.f / frameDeltaTime << std::endl;
		}
	}
	void Application::Tick(float deltaTime)
	{
		
	}

	void Application::Render()
	{

	}
}