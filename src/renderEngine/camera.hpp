#pragma once 

#include "include.hpp"


class Camera {
    public:
        glm::mat4 projection;
        glm::mat4 view;

        Camera(float fov, float aspect, float nearPlane, float farPlane);

        void setPosition(const glm::vec3& eye, const glm::vec3& center, const glm::vec3& up);
        glm::mat4 getViewProjection() const;
};
