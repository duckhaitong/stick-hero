#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"
#include <vector>

namespace Khai
{
	class Hero
	{
	public:
		Hero(GameDataRef data);
		~Hero();

		void Draw();

		void Animate(float dt);

		void Kick(float dt);

		void Run(float dt);

		void Move(float dt);

		void SetPos(float x, float y);

		sf::Sprite &GetSprite();

	private:
		GameDataRef _data;

		sf::Sprite _heroSprite;
		std::vector<sf::Texture> _animationFrames;
		std::vector<sf::Texture> _walkFrames;
		std::vector<sf::Texture> _kickFrames;

		unsigned int _animationIterator;

		sf::Clock _clock;

		sf::Clock _movementClock;

		int _heroState;

	};
}
