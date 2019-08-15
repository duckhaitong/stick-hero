#include "Stick.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>

namespace Khai
{
    Stick::Stick(GameDataRef data) : _data(data)
    {
        _stickSprite.setTexture(this->_data->assets.GetTexture("Stick"));
        _stickSprite.setScale(1.17, 0.0);
    }

    void Stick::SetPos(float x, float y)
	{
	    this->_stickSprite.setPosition(x, y);
	}

    bool Stick::Stretch()
    {

        //this->_stickSprite.setScale(1, - clock.getElapsedTime().asSeconds() * STICK_EXPANDING_SPEED);
        this->_stickSprite.setScale(1, -stick_speed);
        stick_speed += 4.0;
        return true;
    }

    void Stick::Draw()
    {
        this->_data->window.draw(this->_stickSprite);
    }

    void Stick::Rotate()
    {
        if(_stickSprite.getRotation() < 90){
            _stickSprite.rotate(6);
        }
    }

    void Stick::Move(float dt)
    {
        _stickSprite.move(-MOVEMENT_SPEED * dt, 0);
    }

    sf::Sprite &Stick::GetSprite()
    {
        return _stickSprite;
    }

}

