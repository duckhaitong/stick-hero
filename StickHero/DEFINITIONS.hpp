#pragma once

#define SCREEN_WIDTH 469
#define SCREEN_HEIGHT 625

#define SPLASH_STATE_SHOW_TIME 4.0

#define FLASH_SPEED 1500.0f

#define SOUND_BUTTON_CLICK "Resources/sounds/button.wav"
#define SOUND_DEATH "Resources/sounds/death.wav"
#define SOUND_STICK_HIT "Resources/sounds/stick_hit.wav"
#define SOUND_KICK "Resources/sounds/kick.wav"
#define SOUND_SCORE "Resources/sounds/score.wav"
#define SOUND_STICK "Resources/sounds/stick_grow_loop.wav"
#define SOUND_PERFECT "Resources/sounds/perfect.wav"
#define SOUND_FLIP "Resources/sounds/flip.wav"
#define SOUND_FRUIT "Resources/sounds/fruit.wav"
#define MUSIC_BACKGROUND "Resources/sounds/bg_country.wav"


#define SCORE_FONT "Resources/fonts/font.ttf"

#define SPLASH_BACKGROUND_FILEPATH "Resources/images/Splash Background.png"
#define MAIN_MENU_BACKGROUND_1_FILEPATH "Resources/images/Main Menu Background 1.png"
#define MAIN_MENU_BACKGROUND_2_FILEPATH "Resources/images/Main Menu Background 2.png"
#define MAIN_MENU_BACKGROUND_3_FILEPATH "Resources/images/Main Menu Background 3.png"
#define MAIN_MENU_BACKGROUND_4_FILEPATH "Resources/images/Main Menu Background 4.png"
#define MAIN_MENU_BACKGROUND_5_FILEPATH "Resources/images/Main Menu Background 5.png"
#define GAME_BACKGROUND_FILEPATH "Resources/images/Game Background.png"
#define GAME_OVER_BACKGROUND_FILEPATH "Resources/images/.png"
#define MAIN_MENU_TITLE_FILEPATH "Resources/images/Game Title.png"
#define PLATFORM_FILEPATH "Resources/images/Platform.png"
#define STICK_FILEPATH "Resources/images/Stick.png"
#define MAIN_MENU_PLAY_BUTTON "Resources/images/Play Button.png"
#define RANKING_BUTTON "Resources/images/Ranking Button.png"
#define HOME_BUTTON "Resources/images/Home Button.png"
#define RETRY_BUTTON "Resources/images/Retry Button.png"
#define RATING_BUTTON "Resources/images/Rating Button.png"
#define SHARE_BUTTON "Resources/images/Share Button.png"
#define SCORE_BOARD "Resources/images/Score Board.png"
#define SOUND_ON "Resources/images/Sound On.png"
#define SOUND_OFF "Resources/images/Sound Off.png"
#define ABOUT_BUTTON "Resources/images/About Button.png"
#define ABOUT "Resources/images/About.png"
#define MID_POINT_FILEPATH "Resources/images/midpoint.png"
#define BONUS_FRUIT_FILEPATH "Resources/images/watermelon.png"
#define BONUS_POINT_FILEPATH "Resources/images/perfect.png"
#define EMPTY_FILEPATH "Resources/images/empty.png"

#define STAY_FRAME_1_FILEPATH "Resources/images/Hero/stay1.png"
#define STAY_FRAME_2_FILEPATH "Resources/images/Hero/stay2.png"
#define STAY_FRAME_3_FILEPATH "Resources/images/Hero/stay3.png"
#define STAY_FRAME_4_FILEPATH "Resources/images/Hero/stay4.png"
#define STAY_FRAME_5_FILEPATH "Resources/images/Hero/stay5.png"

#define WALK_FRAME_1_FILEPATH "Resources/images/Hero/walk1.png"
#define WALK_FRAME_2_FILEPATH "Resources/images/Hero/walk2.png"
#define WALK_FRAME_3_FILEPATH "Resources/images/Hero/walk3.png"
#define WALK_FRAME_4_FILEPATH "Resources/images/Hero/walk4.png"
#define WALK_FRAME_5_FILEPATH "Resources/images/Hero/walk5.png"

#define KICK_FRAME_1_FILEPATH "Resources/images/Hero/kick1.png"
#define KICK_FRAME_2_FILEPATH "Resources/images/Hero/kick2.png"
#define KICK_FRAME_3_FILEPATH "Resources/images/Hero/kick3.png"
#define KICK_FRAME_4_FILEPATH "Resources/images/Hero/kick4.png"
#define KICK_FRAME_5_FILEPATH "Resources/images/Hero/kick5.png"

#define HERO_ANIMATION_DURATION 0.5f
#define HERO_KICK_DURATION 0.5f
#define HERO_WALK_DURATION 0.1f
#define HERO_RUN_SPEED 150.f


#define MOVEMENT_SPEED 250.0f
#define STICK_EXPANDING_SPEED 35.f
#define ROTATION_SPEED 0.7f

//            if(platform->GetSprite().getPosition().x < 0 || _platform->GetSprite().getPosition().x < 0){ // actually  = -0.00...
//                stick->GetSprite().setRotation(0);
//                stick->GetSprite().setScale(1.17, -0.1);
//                stick->SetPos(hero->GetSprite().getPosition().x + hero->GetSprite().getGlobalBounds().width, hero->GetSprite().getPosition().y + hero->GetSprite().getGlobalBounds().height - 1.7f);
//                //tmp = 1;
//            }



//if(platform->GetSprite().getPosition().x > SCREEN_WIDTH || platform->GetSprite().getPosition().x < 0)
//                    tmp = _platform->GetSprite().getPosition().x;
//                if(_platform->GetSprite().getPosition().x > SCREEN_WIDTH || _platform->GetSprite().getPosition().x < 0)
//                    tmp = platform->GetSprite().getPosition().x;
//                if(platform->GetSprite().getPosition().x < SCREEN_WIDTH && _platform->GetSprite().getPosition().x < SCREEN_WIDTH)
//                    tmp = platform->GetSprite().getPosition().x > _platform->GetSprite().getPosition().x ? platform->GetSprite().getPosition().x : _platform->GetSprite().getPosition().x;
//            //}
//
//            //find the farther point
//
//            if(tmp > 0 && hero->GetSprite().getPosition().x > tmp){
//                platform->Move(dt);
//                _platform->Move(dt);
//                hero->Move(dt);
//                stick->Move(dt);
//            }
//            std::cout << tmp << std::endl;
//
///if(_platform->GetSprite().getPosition().x > platform->GetSprite().getPosition().x){
///            bool tmp = (hero->GetSprite().getPosition().x + hero->GetSprite().getGlobalBounds().width  > stick->GetSprite().getGlobalBounds().width + platform->GetSprite().getGlobalBounds().width) ? true : false;
///            if( platform->GetSprite().getGlobalBounds().width + stick->GetSprite().getGlobalBounds().width < _platform->GetSprite().getPosition().x && tmp)
///                //|| (platform->GetSprite().getGlobalBounds().width + stick->GetSprite().getGlobalBounds().width > _platform->GetSprite().getPosition().x + _platform->GetSprite().getGlobalBounds().width && tmp) )
///                return false;
///            return true;
///        }else{
//            bool tmp = (hero->GetSprite().getPosition().x + hero->GetSprite().getGlobalBounds().width  > stick->GetSprite().getGlobalBounds().width + _platform->GetSprite().getGlobalBounds().width) ? true : false;
//            if( _platform->GetSprite().getGlobalBounds().width + stick->GetSprite().getGlobalBounds().width < platform->GetSprite().getPosition().x && tmp)
//                //|| (_platform->GetSprite().getGlobalBounds().width + stick->GetSprite().getGlobalBounds().width > platform->GetSprite().getPosition().x + platform->GetSprite().getGlobalBounds().width && tmp) )
//                return false;
//            return true;
//        }
//
//        point = platform->GetSprite().getPosition().x + platform->GetSprite().getGlobalBounds().width;
//        _point = _platform->GetSprite().getPosition().x + _platform->GetSprite().getGlobalBounds().width;
//        float stop_point = point > _point ? point : _point;
//
//        if(runable && hero->GetSprite().getPosition().x + hero->GetSprite().getGlobalBounds().width < stop_point){
//            hero->Run(dt);
//        }
//        else
//            hero->Animate(dt);
//
//        //Check get point or die
//        if(!Passable()){ // will fall down
//            hero->GetSprite().move(0, 35);
//            if(stick->GetSprite().getRotation() < 180){
//                stick->GetSprite().rotate(7);
//            }
//        } else { // get point and go to next platform
//
//        }
