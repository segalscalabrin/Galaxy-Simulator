#include "planetCompute.hpp"

PlanetCompute::PlanetCompute(std::vector<glm::vec3> initPosition, std::vector<float> radius, std::vector<glm::vec4> color) {
    this->position = initPosition;
    this->radius = radius;
    this->color = color;
}


