#include "scene.hpp"


Scene::Scene() {
    _planetGroup.addPlanet(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), 5e10f, 1.5f, glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));         // Jaune
    _planetGroup.addPlanet(glm::vec3(5, 0, 5), glm::vec3(0.5, 0, -0.5), 1e9f, 0.5f, glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));     // Vert
    _planetGroup.addPlanet(glm::vec3(-5, 0, -5), glm::vec3(-0.5, 0, 0.5), 1e9f, 0.5f, glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));   // Rouge 
    _planetGroup.addPlanet(glm::vec3(7, 0, -5), glm::vec3(-0.5, 0, -0.5), 1e9f, 0.5f, glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));   // Bleu
    _planetGroup.addPlanet(glm::vec3(-5, 0, 6), glm::vec3(-0.5, 0, -0.5), 1e9f, 0.5f, glm::vec4(1.0f, 0.0f, 1.0f, 1.0f));   // Magenta
}

void Scene::update(float deltaTime)
{
    _planetGroup.compute(deltaTime);
}

void Scene::draw(GLuint shaderID, const glm::mat4 viewProj) const
{
    const std::vector<glm::vec3> position = _planetGroup.getPosition();
    const std::vector<float>     radius   = _planetGroup.getRadius();
    const std::vector<glm::vec4> color    = _planetGroup.getColor();

    for (int i=0; i<position.size(); i++) {
        _shapes.sphere.draw(position[i], radius[i], color[i], shaderID, viewProj);
    }
}
