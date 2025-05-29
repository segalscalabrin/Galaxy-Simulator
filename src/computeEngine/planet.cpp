#include "planet.hpp"

PlanetGroup::PlanetGroup() {}



void PlanetGroup::addPlanet(glm::vec3 position, float radius, glm::vec4 color) {
    _planetCount++;

    _position.push_back(position);
    _radius.push_back(radius);
    _color.push_back(color);
}


const std::vector<glm::vec3> PlanetGroup::getPosition() const {
    return _position;
}
const std::vector<float>     PlanetGroup::getRadius() const {
    return _radius;
}
const std::vector<glm::vec4> PlanetGroup::getColor() const {
    return _color;
}
