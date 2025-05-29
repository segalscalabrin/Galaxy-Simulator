#pragma once

#include "include.hpp"

#include "camera.hpp"
#include "shaders.hpp"
#include "shapes.hpp"

GLFWwindow* initOpenGL();

GLuint initShader();

Camera initCamera();

Shapes initShapes();