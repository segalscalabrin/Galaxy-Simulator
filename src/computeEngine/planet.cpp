#include "planet.hpp"


PlanetGroup::PlanetGroup() {
    _planetCount = 0;

}


void PlanetGroup::addPlanet(glm::vec3 position, glm::vec3 velocity, float mass, float radius, glm::vec4 color) {
    _planetCount++;

    _position.push_back(position);
    _velocity.push_back(velocity);
    _mass.push_back(mass);
    _radius.push_back(radius);
    _color.push_back(color);
}


const std::vector<glm::vec3> PlanetGroup::getPosition() const {
    return _position;
}
const std::vector<glm::vec3> PlanetGroup::getVelocity() const {
    return _velocity;
}
const std::vector<float> PlanetGroup::getMass() const {
    return _mass;
}
const std::vector<float>     PlanetGroup::getRadius() const {
    return _radius;
}
const std::vector<glm::vec4> PlanetGroup::getColor() const {
    return _color;
}


void PlanetGroup::compute(float deltaTime) {
    std::vector<glm::vec3> newPosition(_planetCount);


    for(int i=0; i<_planetCount; i++) {
        newPosition[i] = computeNextPosition(i, deltaTime, _position[i]);
    }

    _position = newPosition;
}

glm::vec3 PlanetGroup::computeNextPosition(int index, float deltaTime, glm::vec3 position) {
    glm::vec3 gravityVect = {0, 0, 0};

    for(int i=0; i<_planetCount; i++) {
        if (index==i) continue;

        gravityVect += computeGravityForce(_position[index], _mass[index], _position[i], _mass[i]);

    } 
    
    _velocity[index] +=  deltaTime * (gravityVect / _mass[index]);
    position +=  deltaTime * _velocity[index];

    return position;
}

glm::vec3 PlanetGroup::computeGravityForce(glm::vec3 position1, float mass1, glm::vec3 position2, float mass2) {
    glm::vec3 distanceVect = {
        position2.x - position1.x,
        position2.y - position1.y,
        position2.z - position1.z
    };

    float inverseDistanceNorm = 1.0/sqrt(distanceVect.x * distanceVect.x + distanceVect.y * distanceVect.y + distanceVect.z * distanceVect.z + 1e-6f);

    float gravityForce = _G * mass1 * mass2 * inverseDistanceNorm * inverseDistanceNorm * inverseDistanceNorm;

    glm::vec3 gravityVect = {
        distanceVect.x * gravityForce,
        distanceVect.y * gravityForce,
        distanceVect.z * gravityForce
    };

    return gravityVect;
}