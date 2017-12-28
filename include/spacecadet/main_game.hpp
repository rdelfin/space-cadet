#ifndef SPACE_CADET_MAIN_GAME_HPP
#define SPACE_CADET_MAIN_GAME_HPP

#include <vector>

#include <maguey/maguey.h>
#include <maguey/game_object.h>

class MainGame : public Game {
public:
    MainGame();
    ~MainGame();
protected:
    void update(GameTime& gameTime) override;
    void draw() override;

private:
    Camera camera;
    Skybox* cubemap;
    std::vector<GameObject> objects;
};

#endif