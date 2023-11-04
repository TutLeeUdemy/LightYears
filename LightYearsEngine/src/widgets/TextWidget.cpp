#include "widgets/TextWidget.h"
#include "framework/AssetManager.h"
namespace ly
{
	TextWidget::TextWidget(const std::string& textStr, const std::string& fontPath, unsigned int characterSize)
		:mFont{AssetManager::Get().LoadFont(fontPath)},
		mText {textStr, *(mFont.get()), characterSize}
	{
		
	}
	
	void TextWidget::SetString(const std::string& newStr)
	{
		mText.setString(newStr);
	}

	void TextWidget::SetTextSize(unsigned int newSize)
	{
		mText.setCharacterSize(newSize);
	}

	sf::FloatRect TextWidget::GetBound() const
	{
		return mText.getGlobalBounds();
	}

	void TextWidget::LocationUpdated(const sf::Vector2f& newLocation)
	{
		mText.setPosition(newLocation);
	}
	void TextWidget::RotationUpdated(float newRotation)
	{
		mText.setRotation(newRotation);
	}
	void TextWidget::Draw(sf::RenderWindow& windowRef)
	{
		windowRef.draw(mText);
	}
}