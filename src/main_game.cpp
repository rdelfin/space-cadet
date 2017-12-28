#include <spacecadet/main_game.hpp>

MainGame::MainGame() : Game("Space Cadet", glm::ivec2(2160, 1440), true), camera(getWindow()) {
    this->camera.reposition(glm::vec3(15, 3, 0), glm::vec3(-15, -3, 0), glm::vec3(0, 1, 0));
    ObjLoader loader;

    this->cubemap = new Skybox;
    this->cubemap->load("resources/textures/space-box/right.png",
                        "resources/textures/space-box/left.png",
                        "resources/textures/space-box/top.png",
                        "resources/textures/space-box/bottom.png",
                        "resources/textures/space-box/front.png",
                        "resources/textures/space-box/back.png",
                        camera);

    auto * m1 = new TriangleMesh;
    m1->load("resources/models/teapot.obj", loader, 
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

    // Exit key
    if(key().isPressed(GLFW_KEY_ESCAPE))
        glfwSetWindowShouldClose(getWindow(), GL_TRUE);
}

void MainGame::draw() {
    this->cubemap->draw();

    for(GameObject& obj : this->objects)
        obj.draw();
}

MainGame::~MainGame() {
    delete cubemap;
}