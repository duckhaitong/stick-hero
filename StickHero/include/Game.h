#ifndef GAME_H
#define GAME_H


class Game
{
private:
    void initWindow();

    public:
        Game();
        virtual ~Game();
    //Funtions
        void updateSFMLEvents();
        void update();
        void render();
        void run();
};

#endif // GAME_H
