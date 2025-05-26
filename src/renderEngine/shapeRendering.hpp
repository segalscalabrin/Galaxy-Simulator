#pragma once 

#include "include.hpp"


class SphereRendering {
    private:
        GLuint vao, vbo, ebo;
        size_t indexCount;

        std::vector<glm::vec3> vertexList;
        std::vector<uint> indexList;

    public:
        SphereRendering();

        void createBaseIcosphere();
        void uploadToOpenGL();

        void draw(const glm::vec3 position, float radius, const glm::vec4 color, GLuint shaderID, const glm::mat4 viewProj) const;
};