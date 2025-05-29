#include "initRenderEngine.hpp"

GLFWwindow* initOpenGL() {
    // 1. Initialisation de GLFW (gestion de la fenêtre et du contexte OpenGL)
    if (!glfwInit()) {
        std::cerr << "[Erreur] Échec de l'initialisation de GLFW" << std::endl;
        return nullptr;
    }

    // 2. Configuration du contexte OpenGL demandé
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);             // OpenGL 4.x
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);             // OpenGL x.5
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Core profile : moderne, sans fonctions obsolètes
    glfwWindowHint(GLFW_SAMPLES, 4);                           // Anti-aliasing (MSAA 4x)

    // 3. Création de la fenêtre
    GLFWwindow* window = glfwCreateWindow(1024, 768, "Simulation 3D - OpenGL", nullptr, nullptr);
    if (!window) {
        std::cerr << "[Erreur] Échec de la création de la fenêtre GLFW" << std::endl;
        glfwTerminate();
        return nullptr;
    }

    glfwMakeContextCurrent(window);  // Active le contexte OpenGL
    glfwSwapInterval(1);             // V-Sync (évite le tearing visuel)

    // 4. Définition de la taille du viewport (correspond à la taille du framebuffer)
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    // 5. Initialisation de GLEW (chargement des fonctions OpenGL modernes)
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        std::cerr << "[Erreur] GLEW init échoué : " << glewGetErrorString(err) << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return nullptr;
    }

    // 6. Activer le test de profondeur (essentiel en 3D pour gérer l'occlusion)
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);  // Le fragment est gardé s'il est plus proche que celui déjà affiché

    // 7. Activer le "face culling" (optionnel mais recommandé)
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);   // Ne pas dessiner les faces arrière (performances)
    glFrontFace(GL_CW);    // Définir le sens des triangles "face avant" (CW = clockwise)

    return window;
}

GLuint initShader() {
    return LoadShaders("assets/SimpleVertexShader.glsl", "assets/SimpleFragmentShader.glsl");
}

Camera initCamera() {
    Camera cam(45.0f, 4.f / 3.f, 0.1f, 100.0f);
    cam.setPosition(glm::vec3(0, 0, 0), glm::vec3(0, 0, -1), glm::vec3(0, 1, 0));
    return cam;
}

Shapes initShapes() {
    Shapes shapes;
    return shapes; 
}

