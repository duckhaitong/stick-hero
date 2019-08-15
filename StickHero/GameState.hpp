#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Platform.hpp"
#include "Hero.hpp"
#include "Stick.hpp"
#include "Flash.hpp"

namespace Khai
{
    class GameState : public State
    {
    public:
        GameState(GameDataRef data, int enable_sound, int N); // N is the highest score that recorded since last play

        void Init();
        void HandleInput();
        void Update(float dt);
        bool Passable();
        void Draw(float dt);

        sf::Text _score;
        sf::Text _best_score;
    private:
        GameDataRef _data;

        //sprites & text
        sf::Sprite _background;
        sf::Sprite _pauseButton;
        sf::Sprite _mid_point;
        sf::Sprite _bonus;
        sf::Sprite _watermelon;
        sf::Sprite _empty;
        sf::Sprite _perfect_point;
        sf::Text _guide;

        //objects
        Platform *platform;
        Hero *hero;
        Stick *stick;
        Flash *flash;

        sf::Clock clock;
        //variables
        int n = 0, tmp = 0, alpha = 0, _alpha = 0, _enable_sound, N = 0;
        int space_count = 0;
        float flag; // determine the point will run to
        bool runable = false;
        bool rotatable = false;
        bool kickable = false;
        bool stop_stretch = false;
        bool stick_too_long = false;
        bool collision = false;
        //sounds & music
        sf::Music music;
        sf::Sound kickSound;
        sf::Sound stick_hitSound;
        sf::Sound deathSound;
        sf::Sound score;
        sf::Sound stick_grow_loop;
        sf::Sound perfect;
        sf::Sound flipSound;
        sf::Sound fruitSound;
        sf::SoundBuffer buff1, buff2, buff3, buff4, buff5, buff6, buff7, buff8;

    };
}
