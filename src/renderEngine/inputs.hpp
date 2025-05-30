#pragma once 

#include "include.hpp"

#include "renderEngine/camera.hpp"


class InputController {
    private:
        GLFWwindow* _window;
        Camera*     _camera;

        float _moveSpeed = 10.0f;
        float _mouseSensitivity = 0.1f;

        void moveCameraPosition(float deltaTime);
        void moveCameraView(float deltaTime);
        void changeSpeed(float deltaTime);

    public:
        InputController(GLFWwindow* window, Camera* camera);

        void processInput(float deltaTime);
};
