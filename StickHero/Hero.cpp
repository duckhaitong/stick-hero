#include "Hero.hpp"
#include "Platform.hpp"
#include <iostream>

namespace Khai
{
	Hero::Hero(GameDataRef data) : _data(data)
	{
		_animationIterator = 0;

		_animationFrames.push_back(this->_data->assets.GetTexture("Stay Frame 1"));
		_animationFrames.push_back(this->_data->assets.GetTexture("Stay Frame 2"));
		_animationFrames.push_back(this->_data->assets.GetTexture("Stay Frame 3"));
		_animationFrames.push_back(this->_data->assets.GetTexture("Stay Frame 4"));
		_animationFrames.push_back(this->_data->assets.GetTexture("Stay Frame 5"));

		_walkFrames.push_back(this->_data->assets.GetTexture("Walk Frame 1"));
		_walkFrames.push_back(this->_data->assets.GetTexture("Walk Frame 2"));
		_walkFrames.push_back(this->_data->assets.GetTexture("Walk Frame 3"));
		_walkFrames.push_back(this->_data->assets.GetTexture("Walk Frame 4"));
		_walkFrames.push_back(this->_data->assets.GetTexture("Walk Frame 5"));

		_kickFrames.push_back(this->_data->assets.GetTexture("Kick Frame 1"));
		_kickFrames.push_back(this->_data->assets.GetTexture("Kick Frame 2"));
		_kickFrames.push_back(this->_data->assets.GetTexture("Kick Frame 3"));
		_kickFrames.push_back(this->_data->assets.GetTexture("Kick Frame 4"));
		_kickFrames.push_back(this->_data->assets.GetTexture("Kick Frame 5"));

		_heroSprite.setTexture(_animationFrames.at(_animationIterator));
		_heroSprite.setScale(0.5f, 0.5f);

		//_heroSprite.setPosition(_platformSprite.getGlobalBounds().width - _heroSprite.getGlobalBounds().width, SCREEN_HEIGHT - _platformSprite.getGlobalBounds().height - _heroSprite.getGlobalBounds().height);
	}

	Hero::~Hero()
	{
        // Destructor
	}

	void Hero::Draw()
	{
		this->_data->window.draw(this->_heroSprite);
	}

	void Hero::Animate(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() > HERO_ANIMATION_DURATION / _animationFrames.size())
		{
		    _animationFrames.at(_animationIterator).setSmooth(true);
			if (_animationIterator < _animationFrames.size() - 1)
			{
				_animationIterator++;
			}
			else
			{
				_animationIterator = 0;
			}

			_heroSprite.setTexture(_animationFrames.at(_animationIterator));

			_clock.restart();
		}
	}

	void Hero::Kick(float dt)
	{
        if (_clock.getElapsedTime().asSeconds() > HERO_KICK_DURATION / _kickFrames.size())
		{
		    _kickFrames.at(_animationIterator).setSmooth(true);
			if (_animationIterator < _kickFrames.size() - 1)
			{
				_animationIterator++;
			}
			else
			{
				_animationIterator = 0;
			}

			_heroSprite.setTexture(_kickFrames.at(_animationIterator));

			_clock.restart();
		}
	}



	void Hero::Run(float dt)
	{
	    if (_clock.getElapsedTime().asSeconds() > HERO_WALK_DURATION / _walkFrames.size())
		{
		    _walkFrames.at(_animationIterator).setSmooth(true);
			if (_animationIterator < _walkFrames.size() - 1)
			{
				_animationIterator++;
			}
			else
			{
				_animationIterator = 0;
			}

			_heroSprite.setTexture(_walkFrames.at(_animationIterator));

			_clock.restart();
		}
        this->_heroSprite.move(HERO_RUN_SPEED * dt, 0);
	}

	void Hero::Move(float dt)
	{
	    _heroSprite.move(-MOVEMENT_SPEED * dt, 0);
	}

	void Hero::SetPos(float x, float y)
	{
	    this->_heroSprite.setPosition(x, y);
	}

	sf::Sprite &Hero::GetSprite()
	{
		return _heroSprite;
	}
}
