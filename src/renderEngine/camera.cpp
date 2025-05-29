#include "camera.hpp"

Camera::Camera(float fov, float aspect, float nearPlane, float farPlane)
{
    projection = glm::perspective(glm::radians(fov), aspect, nearPlane, farPlane);
    view = glm::mat4(1.0f);
}

void Camera::setPosition(const glm::vec3& eye, const glm::vec3& center, const glm::vec3& up)
{
    view = glm::lookAt(eye, center, up);
}

glm::mat4 Camera::getViewProjection() const
{
    return projection * view;
}
