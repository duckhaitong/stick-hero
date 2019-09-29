#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameOverState.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"

#include <iostream>

namespace Khai
{
	GameOverState::GameOverState(GameDataRef data, sf::Text score, int N, int _enable_sound) : _data(data), _score(score), _N(N), enable_sound(_enable_sound)
	{
        _score.setFillColor(sf::Color(35, 35, 35));
        _best_score.setFillColor(sf::Color(35, 35, 35));
	}

	void GameOverState::Init()
	{
	    if(!_soundButtonBuffer.loadFromFile(SOUND_BUTTON_CLICK)){
            //...
        }
        _soundButton.setBuffer(_soundButtonBuffer);

        _music.openFromFile(MUSIC_BACKGROUND);

        if(enable_sound&1){
            _soundButton.setVolume(0);
            _music.setVolume(0);
        }

        _music.setLoop(true);
        _music.play();

		this->_data->assets.LoadTexture("Home Button", HOME_BUTTON);
        this->_data->assets.LoadTexture("Share Button", SHARE_BUTTON);
        this->_data->assets.LoadTexture("Ranking Button", RANKING_BUTTON);
        this->_data->assets.LoadTexture("Rating Button", RATING_BUTTON);
        this->_data->assets.LoadTexture("Retry Button", RETRY_BUTTON);
        this->_data->assets.LoadTexture("Score Board", SCORE_BOARD);

        this->_data->assets.GetTexture("Home Button").setSmooth(true);
        this->_data->assets.GetTexture("Share Button").setSmooth(true);
        this->_data->assets.GetTexture("Ranking Button").setSmooth(true);
        this->_data->assets.GetTexture("Rating Button").setSmooth(true);
        this->_data->assets.GetTexture("Retry Button").setSmooth(true);
        this->_data->assets.GetTexture("Score Board").setSmooth(true);

		_homeButton.setTexture(this->_data->assets.GetTexture("Home Button"));
		_shareButton.setTexture(this->_data->assets.GetTexture("Share Button"));
        _rankingButton.setTexture(this->_data->assets.GetTexture("Ranking Button"));
        _ratingButton.setTexture(this->_data->assets.GetTexture("Rating Button"));
        _retryButton.setTexture(this->_data->assets.GetTexture("Retry Button"));
        _scoreBoard.setTexture(this->_data->assets.GetTexture("Score Board"));

        _best_score.setFont(this->_data->assets.GetFont("Score font"));
        _best_score.setString(std::to_string(_N));
        _best_score.setCharacterSize(35);

        _shareButton.setScale(1.17f, 1.17f);
        _shareButton.setPosition(SCREEN_WIDTH/2 - _shareButton.getGlobalBounds().width/2, SCREEN_HEIGHT/2 - _shareButton.getGlobalBounds().height/2);
        _rankingButton.setPosition(SCREEN_WIDTH/2 - _rankingButton.getGlobalBounds().width - 2.5, 400.0f);
        _homeButton.setPosition(SCREEN_WIDTH/2 - _homeButton.getGlobalBounds().width * 2 - 7, 400.0f);
        _ratingButton.setPosition(SCREEN_WIDTH/2 + 2.5, 400.0f);
        _retryButton.setPosition(SCREEN_WIDTH/2 + _retryButton.getGlobalBounds().width + 7, 400.0f);
        _scoreBoard.setPosition(SCREEN_WIDTH/2 - _scoreBoard.getGlobalBounds().width/2, 100.0f);
	}


	void GameOverState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type || (event.type ==  sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
			{
				this->_data->window.close();
			}

			if(this->_data->input.IsSpriteClicked(this->_retryButton,  sf::Mouse::Left, this->_data->window))
            {
                _music.stop();
                _soundButton.play();
                this->_data->machine.RemoveState();
                this->_data->machine.AddState(StateRef(new GameState(_data, enable_sound, _N)), true);
            }

            if(this->_data->input.IsSpriteClicked(this->_homeButton,  sf::Mouse::Left, this->_data->window))
            {
                _music.stop();
                _soundButton.play();
                this->_data->machine.RemoveState();
                this->_data->machine.AddState(StateRef(new MainMenuState(_data, _N)), true);
            }
		}
	}

	void GameOverState::Update(float dt)
	{
        _score.setPosition(_shareButton.getPosition().x + _shareButton.getGlobalBounds().width / 2 - _score.getGlobalBounds().width / 2, 130);
        _best_score.setPosition(_shareButton.getPosition().x + _shareButton.getGlobalBounds().width / 2 - _best_score.getGlobalBounds().width / 2, 190);
        if(_retryButton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(this->_data->window)))){
            _retryButton.setColor(sf::Color(255, 255, 255, 222));
        } else {
            _retryButton.setColor(sf::Color(255, 255, 255, 255));
        }
        if(_homeButton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(this->_data->window)))){
            _homeButton.setColor(sf::Color(255, 255, 255, 222));
        } else {
            _homeButton.setColor(sf::Color(255, 255, 255, 255));
        }
        if(_shareButton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(this->_data->window)))){
            _shareButton.setColor(sf::Color(255,192,203));
        } else {
            _shareButton.setColor(sf::Color(255, 255, 255));
        }
        if(_rankingButton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(this->_data->window)))){
            _rankingButton.setColor(sf::Color(255, 255, 255, 222));
        } else {
            _rankingButton.setColor(sf::Color(255, 255, 255, 255));
        }
        if(_ratingButton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(this->_data->window)))){
            _ratingButton.setColor(sf::Color(255, 255, 255, 222));
        } else {
            _ratingButton.setColor(sf::Color(255, 255, 255, 255));
        }
	}

	void GameOverState::Draw(float dt)
	{
	    sf::Shader _blur;
	    _blur.loadFromFile("Resources/blur.frag", sf::Shader::Type::Fragment);
	    _blur.setUniform("blur_radius", 0.0017f);
	    _background.setTexture(this->_data->assets.GetTexture("Game Background"));
        //_background.setColor(sf::Color(192,192,192));

	    this->_data->window.draw(_background, &_blur);

		this->_data->window.draw(_homeButton);
		this->_data->window.draw(_rankingButton);
		this->_data->window.draw(_ratingButton);
		this->_data->window.draw(_retryButton);
		this->_data->window.draw(_shareButton);
		this->_data->window.draw(_scoreBoard);
		this->_data->window.draw(_score);
		this->_data->window.draw(_best_score);

		this->_data->window.display();
	}
}
