#include <bits/stdc++.h>
#include "GameState.hpp"
#include "DEFINITIONS.hpp"
#include "GameOverState.hpp"
#include <iostream>

namespace Khai
{
    GameState::GameState(GameDataRef data, int enable_sound, int _N) : _data(data), _enable_sound(enable_sound), N(_N) //Constructor member initializer lists, _data is a private member
    {

    }

    void GameState::Init()
    {
        buff1.loadFromFile(SOUND_KICK);
        kickSound.setBuffer(buff1);
        buff2.loadFromFile(SOUND_STICK_HIT);
        stick_hitSound.setBuffer(buff2);
        buff3.loadFromFile(SOUND_DEATH);
        deathSound.setBuffer(buff3);
        buff4.loadFromFile(SOUND_STICK);
        stick_grow_loop.setBuffer(buff4);
        buff5.loadFromFile(SOUND_SCORE);
        score.setBuffer(buff5);
        buff6.loadFromFile(SOUND_PERFECT);
        perfect.setBuffer(buff6);
        buff7.loadFromFile(SOUND_FLIP);
        flipSound.setBuffer(buff7);
        buff8.loadFromFile(SOUND_FRUIT);
        fruitSound.setBuffer(buff8);


        music.openFromFile(MUSIC_BACKGROUND);

        if(_enable_sound&1){ // odd
            stick_grow_loop.setVolume(0);
            score.setVolume(0);
            kickSound.setVolume(0);
            stick_hitSound.setVolume(0);
            deathSound.setVolume(0);
            perfect.setVolume(0);
            flipSound.setVolume(0);
            fruitSound.setVolume(0);
            music.setVolume(0);
        } else {
            stick_grow_loop.setVolume(50);
            score.setVolume(70);
            kickSound.setVolume(70);
            stick_hitSound.setVolume(70);
            perfect.setVolume(70);
            flipSound.setVolume(17);
            deathSound.setVolume(50);
        }


        music.setLoop(true);
        music.play();

        this->_data->assets.LoadFont("Score font", SCORE_FONT);
        std::string guide = "Hold Space button to stretch out the stick";
        _guide.setFont(this->_data->assets.GetFont("Score font"));
        _guide.setString(guide);
        _guide.setCharacterSize(17);
        //_guide.setFillColor(sf::Color::Black);
        _guide.setPosition((SCREEN_WIDTH / 2) - (_guide.getGlobalBounds().width / 2), 120);

        _score.setFont(this->_data->assets.GetFont("Score font"));
        _score.setString(std::to_string(n));
        _score.setCharacterSize(35);
        _score.setPosition((SCREEN_WIDTH / 2) - (_score.getGlobalBounds().width / 2), 61.6);

        this->_data->assets.LoadTexture("Empty", EMPTY_FILEPATH);
        _empty.setTexture(this->_data->assets.GetTexture("Empty"));
        _empty.setScale(0.35, 0.35);
        _empty.setPosition(190, 60);


        this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
        this->_data->assets.LoadTexture("Platform", PLATFORM_FILEPATH);
        this->_data->assets.LoadTexture("Stick", STICK_FILEPATH);
        this->_data->assets.LoadTexture("Midpoint", MID_POINT_FILEPATH);
        this->_data->assets.LoadTexture("Bonus", BONUS_FRUIT_FILEPATH);
        this->_data->assets.LoadTexture("Perfect", BONUS_POINT_FILEPATH);

        this->_data->assets.LoadTexture("Stay Frame 1", STAY_FRAME_1_FILEPATH);
		this->_data->assets.LoadTexture("Stay Frame 2", STAY_FRAME_2_FILEPATH);
		this->_data->assets.LoadTexture("Stay Frame 3", STAY_FRAME_3_FILEPATH);
		this->_data->assets.LoadTexture("Stay Frame 4", STAY_FRAME_4_FILEPATH);
		this->_data->assets.LoadTexture("Stay Frame 5", STAY_FRAME_5_FILEPATH);

		this->_data->assets.LoadTexture("Walk Frame 1", WALK_FRAME_1_FILEPATH);
		this->_data->assets.LoadTexture("Walk Frame 2", WALK_FRAME_2_FILEPATH);
		this->_data->assets.LoadTexture("Walk Frame 3", WALK_FRAME_3_FILEPATH);
		this->_data->assets.LoadTexture("Walk Frame 4", WALK_FRAME_4_FILEPATH);
		this->_data->assets.LoadTexture("Walk Frame 5", WALK_FRAME_5_FILEPATH);

		this->_data->assets.LoadTexture("Kick Frame 1", KICK_FRAME_1_FILEPATH);
		this->_data->assets.LoadTexture("Kick Frame 2", KICK_FRAME_2_FILEPATH);
		this->_data->assets.LoadTexture("Kick Frame 3", KICK_FRAME_3_FILEPATH);
		this->_data->assets.LoadTexture("Kick Frame 4", KICK_FRAME_4_FILEPATH);
		this->_data->assets.LoadTexture("Kick Frame 5", KICK_FRAME_5_FILEPATH);

        _background.setTexture(this->_data->assets.GetTexture("Game Background"));
        _mid_point.setTexture(this->_data->assets.GetTexture("Midpoint"));
        _mid_point.setScale(0.7, 0.5);
        _bonus.setTexture(this->_data->assets.GetTexture("Bonus"));
        _bonus.setScale(0.17, 0.17);
        _perfect_point.setTexture(this->_data->assets.GetTexture("Perfect"));
        _perfect_point.setScale(0.7, 0.7);
        _perfect_point.setPosition(SCREEN_WIDTH/2 - _perfect_point.getGlobalBounds().width/2, 170);
        _watermelon.setTexture(this->_data->assets.GetTexture("Bonus"));
        _watermelon.setScale(0.2225, 0.2225);
        _watermelon.setPosition(SCREEN_WIDTH - _watermelon.getGlobalBounds().width, 0);

        platform = new Platform(_data);
        hero = new Hero(_data);
        stick = new Stick(_data);
        flash = new Flash(_data);

        platform->Init();

        hero->SetPos(platform->GetSprite().at(0).getGlobalBounds().width - hero->GetSprite().getGlobalBounds().width - 7, SCREEN_HEIGHT - platform->GetSprite().at(0).getGlobalBounds().height - hero->GetSprite().getGlobalBounds().height);

        stick->SetPos(hero->GetSprite().getPosition().x + hero->GetSprite().getGlobalBounds().width + 5, hero->GetSprite().getPosition().y + hero->GetSprite().getGlobalBounds().height - 1.7f);

        if(_background.getPosition().x <= -_background.getGlobalBounds().width)
            _background.setPosition(0, 0);

    }

    bool GameState::Passable()
    {
        if(platform->GetSprite().at(0).getPosition().x + platform->GetSprite().at(0).getGlobalBounds().width + stick->GetSprite().getGlobalBounds().width  < platform->GetSprite().at(1).getPosition().x
           && hero->GetSprite().getPosition().x + hero->GetSprite().getGlobalBounds().width > platform->GetSprite().at(0).getGlobalBounds().width + stick->GetSprite().getGlobalBounds().width)
            return false;
        return true;
    }

    void GameState::HandleInput()
    {
        sf::Event event;

        while(this->_data->window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed || (event.type ==  sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            {
                this->_data->window.close();
            }

            if(event.type ==  sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && space_count == 0 && stick->GetSprite().getRotation() == 0)
            {
                stick->Stretch();
                stick_grow_loop.play();
                stop_stretch = true;
                clock.restart();
            }
            if(event.type ==  sf::Event::KeyReleased)
                space_count++;

            if(event.type ==  sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && space_count > 0
               && space_count % 2 != 0 && stick->GetSprite().getRotation() == 90)
            {
                hero->GetSprite().setOrigin(0, 4 * hero->GetSprite().getGlobalBounds().height); // if sprite is not scale to 50% it will be 2 * ...
                hero->GetSprite().setScale(0.5, -0.5);
                //flip hero
            }

            if(event.type ==  sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && space_count > 0
               && space_count % 2 == 0 && stick->GetSprite().getRotation() == 90)
            {
                hero->GetSprite().setOrigin(0, 0);
                hero->GetSprite().setScale(0.5, 0.5);
                //flip hero
            }

            if(event.type ==  sf::Event::KeyReleased && stop_stretch == true)
            {
                if(space_count == 1)
                    kickSound.play();
                else
                    flipSound.play();
                kickable = true;
                rotatable = true;
            }
        }

        if(stick->GetSprite().getRotation() == 90){
                kickable = false;
                runable = true;
        }
    }

    void GameState::Update(float dt)
    {
        flash->Show(dt);

        //show the guide and then hide it
        if(n == 0 && alpha < 255){
            _guide.setFillColor(sf::Color(255, 255, 255, alpha));
            alpha += 3;
        }
        if(n && alpha > 0){
            _guide.setFillColor(sf::Color(255, 255, 255, alpha));
            alpha -= 3;
        }

        _mid_point.setPosition(platform->GetSprite().at(1).getPosition().x + platform->GetSprite().at(1).getGlobalBounds().width / 2 - _mid_point.getGlobalBounds().width / 2
                                  , platform->GetSprite().at(1).getPosition().y);


        //update when you get perfect score
        _perfect_point.setColor(sf::Color(255, 255, 255, _alpha));
        if(stick->GetSprite().getRotation() == 90 && stick->GetSprite().getPosition().x + stick->GetSprite().getGlobalBounds().width > _mid_point.getPosition().x
           && stick->GetSprite().getPosition().x + stick->GetSprite().getGlobalBounds().width < _mid_point.getPosition().x + 7){
            kickSound.play();
            _alpha = 255;
        }
        if(_alpha) //fade effect
            _alpha -= 3;


        if(kickable)
        {
            if(clock.getElapsedTime().asSeconds() > 0.35f)
                stick_hitSound.play();
            hero->Kick(dt);
        }

        if(rotatable && clock.getElapsedTime().asSeconds() > 0.22f){
            stick->Rotate();
        }

        hero->Animate(dt);

        if(stick->GetSprite().getPosition().x + stick->GetSprite().getGlobalBounds().width > platform->GetSprite().at(1).getPosition().x + platform->GetSprite().at(1).getGlobalBounds().width
           && runable){
               stick_too_long = true;
               if(hero->GetSprite().getPosition().x + hero->GetSprite().getGlobalBounds().width < stick->GetSprite().getPosition().x + stick->GetSprite().getGlobalBounds().width && clock.getElapsedTime().asSeconds() > 0.7f){
                _background.move(-0.35, 0);
                hero->Run(dt);
               }
        }else if(hero->GetSprite().getPosition().x + hero->GetSprite().getGlobalBounds().width < platform->GetSprite().at(1).getPosition().x + platform->GetSprite().at(1).getGlobalBounds().width - 7
           && stick->GetSprite().getGlobalBounds().height != 0 && clock.getElapsedTime().asSeconds() > 0.7f && runable){ // ??? temporary solution
            _background.move(-0.35, 0);
            hero->Run(dt);
        }

        if(hero->GetSprite().getPosition().x + hero->GetSprite().getGlobalBounds().width > platform->GetSprite().at(1).getPosition().x){
            space_count = 0; // reset counter of space button
        }

        _bonus.setPosition((platform->GetSprite().at(1).getPosition().x - platform->GetSprite().at(0).getGlobalBounds().width) + 17, 430);

        if(hero->GetSprite().getGlobalBounds().intersects(_bonus.getGlobalBounds())){
            fruitSound.play();
            _bonus.setColor(sf::Color(255, 255, 255, 0));
        }

        if(hero->GetSprite().getGlobalBounds().intersects(platform->GetSprite().at(1).getGlobalBounds()))
            collision = true;

        if(!Passable() || collision ||
           (stick_too_long && hero->GetSprite().getPosition().x + hero->GetSprite().getGlobalBounds().width > stick->GetSprite().getPosition().x + stick->GetSprite().getGlobalBounds().width)){ // will fall down
            runable = false;
            hero->GetSprite().move(0, 35);
            if(stick->GetSprite().getRotation() <= 174){
                if(stick->GetSprite().getRotation() == 174)
                    stick->GetSprite().rotate(6);
                else
                    stick->GetSprite().rotate(7);
            }
            deathSound.play();
        } else { // get point and go to next platform
            float destination;
            if(platform->GetSprite().at(0).getPosition().x < 0) // actually = -0,...
                destination = platform->GetSprite().at(1).getPosition().x;

            if(hero->GetSprite().getPosition().x > destination && destination > 0){
                if(n && !stick_too_long){ // skip score 0
                    score.play();
                }
                if(tmp == 0 && stick->GetSprite().getRotation() == 90 && !stick_too_long){ // bullshit code :v
                    n = n + 1;
                    N = std::max(n, N);
                    tmp++;
                }
                _score.setString(std::to_string(n));
                _score.setPosition((SCREEN_WIDTH / 2) - (_score.getGlobalBounds().width / 2), 61.6);
                platform->Move(dt);
                hero->Move(dt);
                stick->Move(dt);
            }


            if(platform->GetSprite().at(1).getPosition().x > -10 && platform->GetSprite().at(1).getPosition().x < 0
               && !stick_too_long){
                clock.restart();
                platform->Spawn();
                _bonus.setColor(sf::Color(255, 255, 255, 255));
                //stop_stretch = false;
                rotatable = false;
                stick->stick_speed = 1;
                stick->GetSprite().setRotation(0);
                stick->GetSprite().setScale(1.17, 0.0);
                stick->SetPos(hero->GetSprite().getPosition().x + hero->GetSprite().getGlobalBounds().width + 5, hero->GetSprite().getPosition().y + hero->GetSprite().getGlobalBounds().height - 1.7f);
                tmp = 0; // bullshit variable :((
            }

            if(platform->GetSprite().at(1).getPosition().x > 245){ /// need improve, random distance ?
                platform->GetSprite().at(1).move(-22.5, 0);
            }
        }

        //Go to Game Over State
        if(hero->GetSprite().getPosition().y == 636)
            clock.restart();
        if(hero->GetSprite().getPosition().y > SCREEN_HEIGHT)
        {
            this->_data->window.setFramerateLimit(0);
            if(clock.getElapsedTime().asSeconds() > 1.22f){
                this->_data->window.setPosition(sf::Vector2i(448, 71 + rand() % 5)); //shake the window
            }

            if(clock.getElapsedTime().asSeconds() > 1.5f){ // time before Game Over appear
                music.stop();
                this->_data->machine.AddState(StateRef(new GameOverState(_data, _score, N, _enable_sound)), true);
            }
        }

    }


    void GameState::Draw(float dt)
    {
        this->_data->window.clear();
        this->_data->window.draw(_background);
        this->_data->window.draw(_watermelon);
        this->_data->window.draw(_empty);
        this->_data->window.draw(_score);
        this->_data->window.draw(_guide);

        platform->Draw();
        this->_data->window.draw(_mid_point);
        this->_data->window.draw(_bonus);
        this->_data->window.draw(_perfect_point);

        hero->Draw();
        stick->Draw();
        flash->Draw();

        this->_data->window.display();
    }
}

