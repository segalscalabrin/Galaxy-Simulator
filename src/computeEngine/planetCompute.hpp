#pragma once

#include "include.hpp"

#include "renderEngine/shapeRendering.hpp"

class PlanetCompute {
    private:
        std::vector<glm::vec3> position;
        std::vector<float> radius;
        std::vector<glm::vec4> color;

    public:
        PlanetCompute(std::vector<glm::vec3> initPosition, std::vector<float> radius, std::vector<glm::vec4> color);

};