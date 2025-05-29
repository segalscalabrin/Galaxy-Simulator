#pragma once

#include "include.hpp"

#include "computeEngine/planet.hpp"
#include "renderEngine/shapes.hpp"


class Scene {
    private:
        Shapes _shapes;
        PlanetGroup _planetGroup;

    public:
        Scene();

        void update(float deltaTime);
        void draw(GLuint shaderID, const glm::mat4 viewProj) const;
};
