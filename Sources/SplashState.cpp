#include <sstream>
#include "SplashState.hpp"
#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>

namespace Khai
{
    SplashState::SplashState(GameDataRef data) : _data(data)
    {
        _background.setColor(sf::Color(255, 255, 255, 0));
    }
    void SplashState::Init()
    {
        //system("dir");
        this->_data->assets.LoadTexture("Splash State Background", SPLASH_BACKGROUND_FILEPATH);
        _background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
    }

    void SplashState::HandleInput()
    {
        sf::Event event;

        while(this->_data->window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                this->_data->window.close();
            }
        }
    }

    void SplashState::Update(float dt)
    {
            if(alpha < 0){
                this->_data->machine.AddState(StateRef(new MainMenuState(_data, 0)), true); //Switch to Main Menu
            }else{
                if(_clock.getElapsedTime().asSeconds() < SPLASH_STATE_SHOW_TIME){
                    _background.setColor(sf::Color(255, 255, 255, alpha));
                    alpha++;
                }

                if(_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME + 0.7f){
                    _background.setColor(sf::Color(255, 255, 255, alpha));
                    alpha--;
                }
            }
    }

    void SplashState::Draw(float dt)
    {
        this->_data->window.clear();
        this->_data->window.draw(this->_background);
        this->_data->window.display();
    }
}
