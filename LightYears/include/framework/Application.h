#pragma once
#include <SFML/Graphics.hpp>

namespace ly
{
	class Application
	{
	public:
		Application();
		void Run();
	private:
		void Tick(float deltaTime);
		void Render();
		sf::RenderWindow mWindow;
		float mTargetFrameRate;
		sf::Clock mTickClock;
	};
}