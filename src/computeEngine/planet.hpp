#pragma once

#include "include.hpp"

class PlanetGroup {
    private:
        int _planetCount;

        std::vector<glm::vec3> _position;
        std::vector<float>     _radius;
        std::vector<glm::vec4> _color;

    public:
        PlanetGroup();

        void addPlanet(glm::vec3 position, float radius, glm::vec4 color);

        const std::vector<glm::vec3> getPosition() const;
        const std::vector<float>     getRadius() const;
        const std::vector<glm::vec4> getColor() const;
};