#include <sstream>
#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"
#include "GameState.hpp"

#include <iostream>

namespace Khai
{
    MainMenuState::MainMenuState(GameDataRef data, int N) : _data(data), _N(N)
    {
        int id = rand() % 5 + 1; // set random background
        if(id == 1)
            this->_data->assets.LoadTexture("Background", MAIN_MENU_BACKGROUND_1_FILEPATH);
        if(id == 2)
            this->_data->assets.LoadTexture("Background", MAIN_MENU_BACKGROUND_2_FILEPATH);
        if(id == 3)
            this->_data->assets.LoadTexture("Background", MAIN_MENU_BACKGROUND_3_FILEPATH);
        if(id == 4)
            this->_data->assets.LoadTexture("Background", MAIN_MENU_BACKGROUND_4_FILEPATH);
        if(id == 5)
            this->_data->assets.LoadTexture("Background", MAIN_MENU_BACKGROUND_5_FILEPATH);
        //Sound
        if(!_soundButtonBuffer.loadFromFile(SOUND_BUTTON_CLICK)){
            //...
        }
        _soundButton.setBuffer(_soundButtonBuffer);
    }

    void MainMenuState::Init()
    {
        this->_data->assets.LoadTexture("Play Button", MAIN_MENU_PLAY_BUTTON);
        this->_data->assets.LoadTexture("Game Title", MAIN_MENU_TITLE_FILEPATH);
        this->_data->assets.LoadTexture("Sound On", SOUND_ON);
        this->_data->assets.LoadTexture("Sound Off", SOUND_OFF);
        this->_data->assets.LoadTexture("About Button", ABOUT_BUTTON);
        this->_data->assets.LoadTexture("About", ABOUT);

        _background.setTexture(this->_data->assets.GetTexture("Background"));
        _playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
        _title.setTexture(this->_data->assets.GetTexture("Game Title"));
        _soundOn.setTexture(this->_data->assets.GetTexture("Sound On"));
        _soundOff.setTexture(this->_data->assets.GetTexture("Sound Off"));
        _aboutButton.setTexture(this->_data->assets.GetTexture("About Button"));
        _about.setTexture(this->_data->assets.GetTexture("About"));

        _playButton.setScale(0.35, 0.35);
        _playButton.setPosition((SCREEN_WIDTH / 2) - (this->_playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->_playButton.getGlobalBounds().height / 2));
		_title.setColor(sf::Color::Black);
		_title.setPosition((SCREEN_WIDTH / 2) - (this->_title.getGlobalBounds().width / 2), this->_title.getGlobalBounds().height * 0.1);

		_soundOn.setPosition(55, 522);
		_soundOn.setScale(0.35, 0.35);
		_soundOff.setPosition(55, 522);
		_soundOff.setScale(0.7, 0.7);
		_aboutButton.setScale(0.35f, 0.35f);
		_aboutButton.setPosition(360, 522);
		_about.setPosition(350 - _about.getGlobalBounds().width + 7, 522 - _about.getGlobalBounds().height + 17);

    }

    void MainMenuState::HandleInput()
    {
        sf::Event event;

        while(this->_data->window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed || (event.type ==  sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            {
                this->_data->window.close();
            }

            if(this->_data->input.IsSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window))
            {

                _soundButton.play();
                this->_data->machine.AddState(StateRef(new GameState(_data, enable_sound, _N)), true); //Switch To Game State
            }

            _soundOff.setColor(sf::Color(255, 255, 255, alpha));

            //std::cout << enable_sound << std::endl;

            if(this->_data->input.IsSpriteClicked(this->_soundOn, sf::Mouse::Left, this->_data->window) && enable_sound % 2 == 0)
            {
                alpha = 255;
            }

            if(event.type == sf::Event::MouseButtonReleased && _soundOn.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(this->_data->window))))
                enable_sound++;

            if(this->_data->input.IsSpriteClicked(this->_soundOn, sf::Mouse::Left, this->_data->window) && enable_sound % 2 != 0)
            {
                alpha = 0;
            }

            if(enable_sound&1){
                _soundButton.setVolume(0);
            }

            if(_playButton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(this->_data->window)))){
                _playButton.setColor(sf::Color(255,192,203));
            } else {
                _playButton.setColor(sf::Color(255, 255, 255));
            }
            //even sound on. odd sound off
        }
    }

    void MainMenuState::Update(float dt)
    {
        //_playButton.getPosition().y = 241.75
        _playButton.move(0, button_move_speed);
        if(_playButton.getPosition().y > 250)
            button_move_speed = -0.17;
        if(_playButton.getPosition().y < 240)
            button_move_speed = 0.17;
    }

    void MainMenuState::Draw(float dt)
    {
        this->_data->window.clear();

        this->_data->window.draw(_background);
        this->_data->window.draw(_playButton);
		this->_data->window.draw(_title);
		this->_data->window.draw(_soundOn);
		this->_data->window.draw(_soundOff);


		this->_data->window.draw(this->_aboutButton);

		if(this->_data->input.IsSpriteClicked(this->_aboutButton, sf::Mouse::Left, this->_data->window))
            this->_data->window.draw(_about);

		this->_data->window.display();
    }
}
