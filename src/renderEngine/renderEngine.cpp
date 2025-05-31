#include "renderEngine.hpp"


RenderEngine::RenderEngine() {
    m_simOptions = std::make_shared<SimulationOptions>();

    m_window = initOpenGL();
    initGraphicsOptions();

    m_camera = std::make_shared<Camera>(m_simOptions);

    m_inputs = std::make_shared<InputController>(m_window, m_camera);

    m_shaders = std::make_shared<Shaders>();
    m_shaders->loadShaders("assets/SimpleVertexShader.glsl", "assets/SimpleFragmentShader.glsl");
}

RenderEngine::~RenderEngine() {
    glfwDestroyWindow(m_window);
    glfwTerminate();
}



GLFWwindow* RenderEngine::initOpenGL() {
    if (!glfwInit()) {
        std::cerr << "[Erreur] Échec de l'initialisation de GLFW" << std::endl;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_SAMPLES, 4);

    GLFWwindow* window = glfwCreateWindow(m_simOptions->screenWidth, m_simOptions->screenHeight, "Simulation 3D - OpenGL - 0 fps", nullptr, nullptr);
    if (!window) {
        std::cerr << "[Erreur] Échec de la création de la fenêtre GLFW" << std::endl;
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);

    GLenum err = glewInit();
    if (err != GLEW_OK) {
        std::cerr << "[Erreur] GLEW init échoué : " << glewGetErrorString(err) << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    return window;
}

void RenderEngine::initGraphicsOptions() {
    glfwSwapInterval(1);           

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);  
    glFrontFace(GL_CW);

    glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}


void RenderEngine::run(std::shared_ptr<Scene> scene) {
    float lastFrame = 0.0f;
    while (!glfwWindowShouldClose(m_window)) {
        float currentFrame = glfwGetTime();
        float deltaTime = 4*(currentFrame - lastFrame);
        lastFrame = currentFrame;

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(m_shaders->getShaders());

        m_inputs->processInput(deltaTime);
        
        scene->update(deltaTime);
        scene->draw(m_shaders->getShaders(), m_camera->getProjectionMatrix() * m_camera->getViewMatrix());

        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
}