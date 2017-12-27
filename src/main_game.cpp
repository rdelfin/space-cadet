#include <spacecadet/main_game.hpp>

MainGame::MainGame() : Game("Space Cadet", glm::ivec2(2160, 1440), true), camera(getWindow()) {
    this->camera.reposition(glm::vec3(15, 3, 0), glm::vec3(-15, -3, 0), glm::vec3(0, 1, 0));
    ObjLoader loader;

    TriangleMesh* m1 = new TriangleMesh;
    m1->load("resources/models/imperial.obj", loader, 
             Shader("resoueces/shaders/default.vert"),
             Shader("resources/shaders/default.geom"),
             Shader("resources/shaders/default.frag"),
             camera);

    this->objects.push_back(GameObject(m1));
}


void MainGame::update(GameTime& gameTime) {
    for(GameObject& object : this->objects)
        object.update(gameTime);

    // Exit key
    if(key().isPressed(GLFW_KEY_ESCAPE))
        glfwSetWindowShouldClose(getWindow(), GL_TRUE);
}

void MainGame::draw() {
    for(GameObject& object : this->objects)
        object.draw();
}

MainGame::~MainGame() {

}