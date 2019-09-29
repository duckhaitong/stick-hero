#include "Platform.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>

namespace Khai
{
    Platform::Platform(GameDataRef data) : _data(data)
    {

    }

    Platform::~Platform()
    {
        //Destructor
        std::cout << "Destructor called";
    }

    void Platform::Init()
    {
        sf::Sprite sprite(this->_data->assets.GetTexture("Platform"));

        sprite.setScale((float)((rand() % 16 + 7)/10.0f), 1);
        sprite.setPosition(sprite.getPosition().x, SCREEN_HEIGHT - sprite.getGlobalBounds().height);
        _platformSprite.push_back(sprite);

        sprite.setScale((float)((rand() % 16 + 7)/10.0f), 1);
        sprite.setPosition(SCREEN_WIDTH - sprite.getGlobalBounds().width - rand() % 20 - 10, SCREEN_HEIGHT - sprite.getGlobalBounds().height);
        _platformSprite.push_back(sprite);
    }

    void Platform::Spawn()
    {
        for(unsigned int i = 0; i < _platformSprite.size(); i++){
            if (_platformSprite[i].getPosition().x < - _platformSprite[i].getLocalBounds().width)
			{
				_platformSprite.erase( _platformSprite.begin( ) + i );
                sf::Sprite sprite(this->_data->assets.GetTexture("Platform"));
                sprite.setScale((float)((rand() % 16 + 7)/10.0f), 1);
                sprite.setPosition(SCREEN_WIDTH, SCREEN_HEIGHT - sprite.getGlobalBounds().height);
                _platformSprite.push_back(sprite);
			}
        }
    }

    void Platform::Move(float dt)
    {
        for(unsigned int i = 0; i < _platformSprite.size(); i++){
            this->_platformSprite[i].move(-MOVEMENT_SPEED * dt, 0);
        }
    }

    void Platform::Draw()
    {
        for(unsigned int i = 0; i < _platformSprite.size(); i++){
            this->_data->window.draw(this->_platformSprite[i]);
        }
    }

    std::vector <sf::Sprite> &Platform::GetSprite()
	{
		return _platformSprite;
	}
}
