#pragma once
#include <cmath>
#include <SFML/Graphics.hpp>

namespace ly
{
	sf::Vector2f RotationToVector(float rotation);
	float DegreesToRadians(float degrees);
	float RadiansToDegrees(float radians);

	template<typename T>
	float GetVectorLength(const sf::Vector2<T>& vector)
	{
		return std::sqrt(vector.x * vector.x + vector.y * vector.y);
	}

	template<typename T>
	sf::Vector2<T>& ScaleVector(sf::Vector2<T>& vectorToScale, float amt)
	{
		vectorToScale.x *= amt;
		vectorToScale.y *= amt;
		return vectorToScale;
	}

	template<typename T>
	sf::Vector2<T>& Normalize(sf::Vector2<T>& vector)
	{
		float vectorLength = GetVectorLength<T>(vector);
		if (vectorLength == 0.f) return vector;

		ScaleVector(vector, 1.0/vectorLength);

		return vector;
	}

	sf::Color LerpColor(const sf::Color& a, const sf::Color& b, float alpha);

	sf::Vector2f LerpVector(const sf::Vector2f& a, const sf::Vector2f& b, float alpha);

	float LerpFloat(float a, float b, float alpha);

	float RandomRange(float min, float max);
	sf::Vector2f RandomUnitVector();
}