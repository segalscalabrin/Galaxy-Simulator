#pragma once

#include "include.hpp"

#include "renderEngine/camera.hpp"
#include "renderEngine/shaders.hpp"
#include "renderEngine/shapes.hpp"

GLFWwindow* initOpenGL();

GLuint initShader();

Camera initCamera();

Shapes initShapes();