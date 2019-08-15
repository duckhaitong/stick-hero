#pragma once

#include "Game.hpp"
#include <SFML/Graphics.hpp>

namespace Khai
{
    class Stick
    {
    public:
        Stick(GameDataRef data);
        void SetPos(float x, float y);

        bool Stretch();

        void Draw();

        void Rotate();

        void Move(float dt);

        sf::Sprite &GetSprite();

        sf::Clock clock;
        int stick_speed = 1;
    private:
        GameDataRef _data;

        sf::Sprite _stickSprite;
        float angle = 0.00017;
    };
}
