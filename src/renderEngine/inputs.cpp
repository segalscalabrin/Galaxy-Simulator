#include "inputs.hpp"

float fovGlob = 80.;

void scrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
    fovGlob -= (float)yoffset * 5;
    fovGlob = glm::clamp(fovGlob, 1.0f, 120.0f);
}


InputController::InputController(GLFWwindow* window, std::shared_ptr<Camera> camera) {
    _window = window;
    _camera = camera;

    glfwSetScrollCallback(window, scrollCallback); 
}


void InputController::moveCameraPosition(float deltaTime) {
    if (glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS) {
        _camera->moveForward(_moveSpeed*deltaTime);
    }
    if (glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS) {
        _camera->moveForward(- _moveSpeed*deltaTime);
    }
    if (glfwGetKey(_window, GLFW_KEY_D) == GLFW_PRESS) {
        _camera->moveRight(_moveSpeed*deltaTime);
    }
    if (glfwGetKey(_window, GLFW_KEY_A) == GLFW_PRESS) {
        _camera->moveRight(- _moveSpeed*deltaTime);
    }
    if (glfwGetKey(_window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        _camera->moveUp(_moveSpeed*deltaTime);
    }
    if (glfwGetKey(_window, GLFW_KEY_Q) == GLFW_PRESS) {
        _camera->moveUp(- _moveSpeed*deltaTime);
    }
}

void InputController::moveCameraView(float deltaTime) {
    static double lastX = 0.0;
    static double lastY = 0.0;
    static bool firstMouse = true;

    double xpos, ypos;
    glfwGetCursorPos(_window, &xpos, &ypos);

    if (firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    double xoffset = xpos - lastX;
    double yoffset = lastY - ypos;

    lastX = xpos;
    lastY = ypos;

    float sensitivity = _mouseSensitivity;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    _camera->rotate(static_cast<float>(xoffset), static_cast<float>(yoffset));
}


void InputController::changeSpeed(float deltaTime) {
    if (glfwGetKey(_window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
        _moveSpeed += 10*deltaTime;
    }
    if (glfwGetKey(_window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
        _moveSpeed -= 10*deltaTime;
    }
    _moveSpeed = glm::clamp(_moveSpeed, 0.1f, 100.0f);
}


void InputController::processInput(float deltaTime) {
    moveCameraPosition(deltaTime);
    moveCameraView(deltaTime);
    changeSpeed(deltaTime);
    _camera->zoom(fovGlob);

}
