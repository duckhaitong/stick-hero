#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Khai
{
    class SplashState : public State
    {
    public:
        SplashState(GameDataRef data);

        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        GameDataRef _data;

        int alpha = 1;
        sf::Clock _clock;
        sf::Sprite _background;
    };
}
