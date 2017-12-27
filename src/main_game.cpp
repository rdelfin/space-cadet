#include <spacecadet/main_game.hpp>

MainGame::MainGame() : Game("Space Cadet", glm::ivec2(2160, 1440), true), camera(getWindow()) {
    camera.reposition(glm::vec3(15, 3, 0), glm::vec3(-15, -3, 0), glm::vec3(0, 1, 0));
}


void MainGame::update(GameTime& gameTime) {
    // Exit key
    if(key().isPressed(GLFW_KEY_ESCAPE))
        glfwSetWindowShouldClose(getWindow(), GL_TRUE);
}

void MainGame::draw() {

}

MainGame::~MainGame() {

}