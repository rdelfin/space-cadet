#include <spacecadet/main_game.hpp>

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

    auto * m1 = new maguey::TriangleMesh;
    m1->load("resources/models/imperial.obj", loader, camera);
    m1->setScale(glm::vec3(0.1, 0.1, 0.1));

    this->objects.emplace_back();
    this->objects[0].addMesh(m1);
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
