#include <spacecadet/main_game.hpp>

#include <iostream>
#include <unordered_map>

MainGame::MainGame() : maguey::Game("Space Cadet", glm::ivec2(1600, 1024), false), camera(getWindow()) {
    this->camera.reposition(glm::vec3(30, 0, 0), glm::vec3(-30, 0, 0), glm::vec3(0, 1, 0));
    maguey::ObjLoader loader;

    this->cubemap = new maguey::Skybox;
    this->cubemap->load("resources/textures/space-box/right.png",
                        "resources/textures/space-box/left.png",
                        "resources/textures/space-box/top.png",
                        "resources/textures/space-box/bot.png",
                        "resources/textures/space-box/front.png",
                        "resources/textures/space-box/back.png",
                        camera);

    this->objects.emplace_back();

    bool error;
    std::unordered_map<std::string, maguey::TriangleMesh*> objs =
        loader.loadFile("resources/models/imperial.obj",
                        error, camera);

    if(error) {
        std::cerr << "There was an error loading file \"resources/models/imperial.obj\"" << std::endl;
        exit(-1);
    }

    for(std::pair<std::string, maguey::TriangleMesh*> pair : objs) {
        pair.second->setScale(glm::vec3(0.1, 0.1, 0.1));
        this->objects[0].addMesh(pair.second);
    }
}


void MainGame::update(maguey::GameTime& gameTime) {
    for(maguey::GameObject& obj : this->objects)
        obj.update(gameTime);

    cam_update(gameTime);

    // Exit key
    if(key().isPressed(GLFW_KEY_ESCAPE))
        glfwSetWindowShouldClose(getWindow(), GL_TRUE);
}

void MainGame::cam_update(maguey::GameTime& gameTime) {
    float spf = (float)(gameTime.getMillisecondsPerFrame() / (long double)1000.0);

    // Pan
    if(this->key().isPressed(GLFW_KEY_UP))
        this->camera.pan(glm::vec3(0, 0, 1000 * spf));
    if(this->key().isPressed(GLFW_KEY_DOWN))
        this->camera.pan(glm::vec3(0, 0, -1000 * spf));
    if(this->key().isPressed(GLFW_KEY_LEFT))
        this->camera.pan(glm::vec3(-1000 * spf, 0, 0));
    if(this->key().isPressed(GLFW_KEY_RIGHT))
        this->camera.pan(glm::vec3(1000 * spf, 0, 0));
    if(this->key().isPressed(GLFW_KEY_O))
        this->camera.pan(glm::vec3(0, 1000 * spf, 0));
    if(this->key().isPressed(GLFW_KEY_L))
        this->camera.pan(glm::vec3(0, -1000 * spf, 0));
    
    // Yaw
    if(this->key().isPressed(GLFW_KEY_A))
        this->camera.yaw(0.3f * spf);
    if(this->key().isPressed(GLFW_KEY_D))
        this->camera.yaw(-0.3f * spf);

    // Pitch
    if(this->key().isPressed(GLFW_KEY_W))
        this->camera.pitch(0.3f * spf);
    if(this->key().isPressed(GLFW_KEY_S))
        this->camera.pitch(-0.3f * spf);

    // Roll
    if(this->key().isPressed(GLFW_KEY_Q))
        this->camera.roll(-0.3f * spf);
    if(this->key().isPressed(GLFW_KEY_E))
        this->camera.roll(0.3f * spf);
}

void MainGame::draw() {
    this->cubemap->draw();

    for(maguey::GameObject& obj : this->objects)
        obj.draw();
}

MainGame::~MainGame() {
    delete cubemap;
}
