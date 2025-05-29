#pragma once 

#include "include.hpp"


class Camera {
    private:
        glm::vec3 _position;

        glm::vec3 _cameraFront;
        glm::vec3 _cameraUp;
        glm::vec3 _cameraRight;

        glm::vec3 _flatFront;

        float _yaw;
        float _pitch;

        float _fov, _aspectRatio, _nearPlane, _farPlane;

        void updateVectors(); 

    public:
        Camera(float fov, float aspect, float nearPlane, float farPlane);

        void setPosition(glm::vec3 position, glm::vec3 lookAt);
        void setProjection(float fov, float aspectRatio, float nearPlane, float farPlane);

        void moveForward(float delta);
        void moveRight(float delta);
        void moveUp(float delta);

        void rotate(float yawOffset, float pitchOffset);

        void zoom(float offset);

        glm::vec3 getPosition() const;
        glm::mat4 getViewMatrix() const;
        glm::mat4 getProjectionMatrix() const;

};
