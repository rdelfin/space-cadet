#ifndef SPACE_CADET_MAIN_GAME_HPP
#define SPACE_CADET_MAIN_GAME_HPP

#include <vector>

#include <maguey/maguey.hpp>
#include <maguey/game_object.hpp>

class MainGame : public maguey::Game {
public:
    MainGame();
    ~MainGame();
protected:
    void update(maguey::GameTime& gameTime) override;
    void draw() override;

private:
    maguey::Camera camera;
    maguey::Skybox* cubemap;
    std::vector<maguey::GameObject> objects;

    void cam_update(maguey::GameTime& gameTime);

};

#endif