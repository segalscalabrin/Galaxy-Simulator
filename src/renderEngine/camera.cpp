#include "camera.hpp"


Camera::Camera(std::shared_ptr<SimulationOptions> simOptions) {
    m_simOptions = simOptions;
    _fov = 80.0f; 
    _aspectRatio = m_simOptions->screenWidth/m_simOptions->screenHeight; 
    _nearPlane = 0.1f; 
    _farPlane = 1000.f;
    _position = glm::vec3(0.0f, 0.0f, 3.0f);
    _yaw = 0.0f;
    _pitch = 0.0f;
    _cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    updateVectors();
}


void Camera::moveForward(float delta) {
    _position += _flatFront * delta;
}

void Camera::moveRight(float delta) {
    _position += _cameraRight * delta;
}

void Camera::moveUp(float delta) {
    _position.y += _cameraUp.y * delta;
}

void Camera::rotate(float yawOffset, float pitchOffset) {
    _yaw += yawOffset;
    _pitch += pitchOffset;

    _pitch = glm::clamp(_pitch, -89.9f, 89.9f);

    updateVectors();
}

void Camera::zoom(float fov) {
    _fov = fov;
}

void Camera::updateVectors() {
    glm::vec3 direction;
    direction.x = cos(glm::radians(_yaw)) * cos(glm::radians(_pitch));
    direction.y = sin(glm::radians(_pitch));
    direction.z = sin(glm::radians(_yaw)) * cos(glm::radians(_pitch));

    _cameraFront = glm::normalize(direction);
    _cameraRight = glm::normalize(glm::vec3(-sin(glm::radians(_yaw)), 0.0f, cos(glm::radians(_yaw))));
    _cameraUp    = glm::normalize(glm::cross(_cameraRight, _cameraFront));

    _flatFront = glm::normalize(glm::vec3(_cameraFront.x, 0.0f, _cameraFront.z));
}


void Camera::setPosition(glm::vec3 position, glm::vec3 lookAt) {
    _position = position;
    _cameraFront = glm::normalize(lookAt - position);
    _cameraUp = glm::normalize(glm::vec3(0, 1, 0));

    _yaw = glm::degrees(atan2(_cameraFront.z, _cameraFront.x));
    _pitch = glm::degrees(asin(_cameraFront.y));

    updateVectors();
}

void Camera::setProjection(float fov, float aspectRatio, float nearPlane, float farPlane) {
    _fov = fov;
    _aspectRatio = aspectRatio; 
    _nearPlane = nearPlane;
    _farPlane = farPlane;
}


glm::vec3 Camera::getPosition() const {
    return _position;
}

glm::mat4 Camera::getViewMatrix() const {
    return glm::lookAt(_position, _position + _cameraFront, _cameraUp);
}

glm::mat4 Camera::getProjectionMatrix() const {
    return glm::perspective(glm::radians(_fov), _aspectRatio, _nearPlane, _farPlane);
}
