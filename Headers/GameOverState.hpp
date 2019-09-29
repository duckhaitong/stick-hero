#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Khai
{
	class GameOverState : public State
	{
	public:
		GameOverState(GameDataRef data, sf::Text score, int _N, int _enable_sound);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _homeButton;
		sf::Sprite _shareButton;
		sf::Sprite _ratingButton;
		sf::Sprite _retryButton;
		sf::Sprite _rankingButton;
		sf::Sprite _scoreBoard;
		sf::Sprite _background;
		sf::Text _gameOver;
		sf::Text _score;
		sf::Text _best_score;

		int _N, enable_sound;

		sf::Music _music;
		sf::Sound _soundButton;
        sf::SoundBuffer _soundButtonBuffer;
	};
}
