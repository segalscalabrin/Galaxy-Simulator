#include "scene.hpp"


Scene::Scene() {
    _planetGroup.addPlanet(glm::vec3(0.5, 0, -3), 0.3f, glm::vec4(0.2f, 0.6f, 1.0f, 1.0f));
    _planetGroup.addPlanet(glm::vec3(-0.5, 0, -3), 0.5f, glm::vec4(0.2f, 0.6f, 1.0f, 1.0f));
}

void Scene::update(float deltaTime)
{
    // Pour plus tard : logique de mouvement des planètes
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
