#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <memory>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


struct SimulationOptions {
    // État général
    bool isPaused = false;

    // Fenêtre
    int screenWidth = 1024;
    int screenHeight = 768;

    // Contrôle caméra
    float cameraMoveSpeed = 5.0f;
    float mouseSensitivity = 0.1f;
    float zoomSpeed = 1.0f;

    // Simulation
    float timeScale = 1.0f;
    bool drawOrbitLines = false;
    bool enablePhysics = true;
};
