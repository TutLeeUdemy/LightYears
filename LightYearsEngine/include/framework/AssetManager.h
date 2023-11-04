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
		template<typename T>
		shared<T> LoadAsset(const std::string& path, Dictionary<std::string, shared<T>>& constainer);
		static unique<AssetManager> assetManager;
		Dictionary<std::string, shared<sf::Texture>> mLoadedTextureMap;
		Dictionary<std::string, shared<sf::Font>> mLoadedFontMap;
		std::string mRootDirectory;

		template<typename T>
		void CleanUniqueRef(Dictionary<std::string, shared<T>>& container);

	};

	template<typename T>
	inline shared<T> AssetManager::LoadAsset(const std::string& path, Dictionary<std::string, shared<T>>& constainer)
	{
		auto found = constainer.find(path);
		if (found != constainer.end())
		{
			return found->second;
		}

		shared<T> newAsset{ new T };
		if (newAsset->loadFromFile(mRootDirectory + path))
		{
			constainer.insert({ path, newAsset });
			return newAsset;
		}

		return shared<T> {nullptr};
	}
	template<typename T>
	inline void AssetManager::CleanUniqueRef(Dictionary<std::string, shared<T>>& container)
	{
		for (auto iter = container.begin(); iter != container.end();)
		{
			if (iter->second.unique())
			{
				LOG("cleaning: %s", iter->first.c_str());
				iter = container.erase(iter);
			}
			else
			{
				++iter;
			}
		}

	}
}