#include <spacecadet/main_game.hpp>

MainGame::MainGame() : Game("Space Cadet", glm::ivec2(2160, 1440), true), camera(getWindow()) {
    this->camera.reposition(glm::vec3(30, 0, 0), glm::vec3(-30, 0, 0), glm::vec3(0, 1, 0));
    ObjLoader loader;

    this->cubemap = new Skybox;
    this->cubemap->load("resources/textures/space-box/right.png",
                        "resources/textures/space-box/left.png",
                        "resources/textures/space-box/top.png",
                        "resources/textures/space-box/bot.png",
                        "resources/textures/space-box/front.png",
                        "resources/textures/space-box/back.png",
                        camera);

    auto * m1 = new TriangleMesh;
    m1->load("resources/models/imperial.obj", loader,
             Shader("resources/shaders/default.vert"),
             Shader("resources/shaders/default.geom"),
             Shader("resources/shaders/default.frag"),
             camera);
    m1->setScale(glm::vec3(0.1, 0.1, 0.1));

    this->objects.push_back(GameObject());
    this->objects[0].addMesh(m1);
}


void MainGame::update(GameTime& gameTime) {
    for(GameObject& obj : this->objects)
        obj.update(gameTime);

    cam_update(gameTime);

    // Exit key
    if(key().isPressed(GLFW_KEY_ESCAPE))
        glfwSetWindowShouldClose(getWindow(), GL_TRUE);
}

void MainGame::cam_update(GameTime& gameTime) {
    double spf = gameTime.getMillisecondsPerFrame() / 1000.0f;

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
        this->camera.yaw(5 * spf);
    if(this->key().isPressed(GLFW_KEY_D))
        this->camera.yaw(-5 * spf);

    // Pitch
    if(this->key().isPressed(GLFW_KEY_W))
        this->camera.pitch(5 * spf);
    if(this->key().isPressed(GLFW_KEY_S))
        this->camera.pitch(-5 * spf);

    // Roll
    if(this->key().isPressed(GLFW_KEY_Q))
        this->camera.roll(5 * spf);
    if(this->key().isPressed(GLFW_KEY_E))
        this->camera.roll(-5 * spf);
}

void MainGame::draw() {
    this->cubemap->draw();

    for(GameObject& obj : this->objects)
        obj.draw();
}

MainGame::~MainGame() {
    delete cubemap;
}
