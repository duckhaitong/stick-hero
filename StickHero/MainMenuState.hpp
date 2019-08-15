#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Khai
{
    class MainMenuState : public State
    {
    public:
        MainMenuState(GameDataRef data, int _N);

        void Init();

        void HandleInput();
        void Update(float dt);
        void Draw(float dt);


    private:
        GameDataRef _data;

        int alpha = 0, enable_sound = 0;
        int _N; // N is the highest score that system recorded it

        sf::Clock clock;
        sf::Sprite _background;
        sf::Sprite _playButton;
        float button_move_speed = 0.17;
        sf::Sprite _title;
        sf::Sprite _aboutButton;
        sf::Sprite _about;
        sf::Sprite _soundOn;
        sf::Sprite _soundOff;

        sf::Sound _soundButton;
        sf::SoundBuffer _soundButtonBuffer;
    };
}
