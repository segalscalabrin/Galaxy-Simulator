#include "initOpenGL.hpp"


GLFWwindow* initOpenGL() {
    GLFWwindow* window;

	// Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Erreur: GLFW init a échoué" << std::endl;
    }

    // Contexte OpenGL 4.5 Core
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
    window = glfwCreateWindow(1024, 768, "Fenêtre OpenGL", NULL, NULL);

    int w, h;
    glfwGetFramebufferSize(window, &w, &h);
    glViewport(0, 0, w, h);

    if (!window) {
        std::cerr << "Erreur: création de la fenêtre a échoué" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);


    // Initialiser GLEW
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        std::cerr << "Erreur: GLEW init a échoué: " << glewGetErrorString(err) << std::endl;
    }

    return window;
}


void closeOpenGL(GLFWwindow*& window) {
    glfwDestroyWindow(window);
    glfwTerminate();
}