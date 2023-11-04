#include "widgets/Widget.h"

namespace ly
{
	void Widget::NativeDraw(sf::RenderWindow& windowRef)
	{
		if (mIsVisible)
		{
			Draw(windowRef);
		}
	}
	bool Widget::HandleEvent(const sf::Event& event)
	{
		return false;
	}

	void Widget::SetWidgetLocation(const sf::Vector2f& newLocation)
	{
		mWidgetTransform.setPosition(newLocation);
		LocationUpdated(newLocation);
	}

	void Widget::SetWidgetRotation(float newRotation)
	{
		mWidgetTransform.setRotation(newRotation);
		RotationUpdated(newRotation);
	}

	void Widget::SetVisiblity(bool newVisibility)
	{
		mIsVisible = newVisibility;
	}

	sf::Vector2f Widget::GetCenterPosition() const
	{
		sf::FloatRect bound = GetBound();
		return sf::Vector2f{bound.left + bound.width/2.f, bound.top + bound.height/2.f};
	}

	Widget::Widget()
		: mIsVisible{true},
		mWidgetTransform{}
	{

	}

	void Widget::Draw(sf::RenderWindow& windowRef)
	{

	}

	void Widget::LocationUpdated(const sf::Vector2f& newLocation)
	{

	}
	void Widget::RotationUpdated(float newRotaion)
	{

	}
}