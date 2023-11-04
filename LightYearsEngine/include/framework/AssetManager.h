#pragma once
#include <SFML/Graphics.hpp>

#include "framework/Core.h"

namespace ly
{
	class AssetManager
	{
	public:
		static AssetManager& Get();
		shared<sf::Texture> LoadTexture(const std::string& path);
		shared<sf::Font> LoadFont(const std::string& path);
		void CleanCycle();
		void SetAssetRootDirectory(const std::string& directory);
	protected:
		AssetManager();
	private:
		static unique<AssetManager> assetManager;
		Dictionary<std::string, shared<sf::Texture>> mLoadedTextureMap;
		Dictionary<std::string, shared<sf::Font>> mLoadedFontMap;
		std::string mRootDirectory;
	};
}