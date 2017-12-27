#ifndef SPACE_CADET_MAIN_GAME_HPP
#define SPACE_CADET_MAIN_GAME_HPP

#include <maguey/maguey.h>

class MainGame : public Game {
public:
    MainGame();
    ~MainGame();
protected:
    void update(GameTime& gameTime) override;
    void draw() override;

private:
    Camera camera;

};

#endif