#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace Khai
{
	class Platform
	{
	public:
		Platform(GameDataRef data);
		~Platform();
        void Init();
		void Spawn();
		void Move(float dt);
		void Draw();
		std::vector <sf::Sprite> &GetSprite();

	private:
		GameDataRef _data;
        std::vector <sf::Sprite> _platformSprite;
	};
}
