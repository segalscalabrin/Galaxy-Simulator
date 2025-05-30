#pragma once

#include "include.hpp"

class PlanetGroup {
    private:
        const float _G = 6.67430e-11f; 

        int _planetCount;

        std::vector<glm::vec3> _position;
        std::vector<glm::vec3> _velocity;
        std::vector<float>     _mass;
        std::vector<float>     _radius;
        std::vector<glm::vec4> _color;

        glm::vec3 computeNextPosition(int index, float deltaTime, glm::vec3 newPosition);
        glm::vec3 computeGravityForce(glm::vec3 position1, float mass1, glm::vec3 position2, float mass2);

    public:
        PlanetGroup();

        void addPlanet(glm::vec3 position, glm::vec3 velocity, float mass, float radius, glm::vec4 color);

        const std::vector<glm::vec3> getPosition() const;
        const std::vector<glm::vec3> getVelocity() const;
        const std::vector<float>     getMass() const;
        const std::vector<float>     getRadius() const;
        const std::vector<glm::vec4> getColor() const;

        void compute(float deltaTime);
};