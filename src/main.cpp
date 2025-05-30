#include "include.hpp"
#include "renderEngine/initRenderEngine.hpp"
#include "renderEngine/inputs.hpp"
#include "computeEngine/initComputeEngine.hpp"

int main() 
{
    GLFWwindow*         window   = initOpenGL();
    Camera*             camera   = new Camera(80.0f, 4.f / 3.f, 0.1f, 100.0f);
    InputController*    inputs   = new InputController(window, camera);
    GLuint              shaderID = initShader();
    Scene               scene    = initScene();

    // Boucle de rendu
    float lastFrame = 0.0f;
    while (!glfwWindowShouldClose(window)) {
        float currentFrame = glfwGetTime();
        float deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(shaderID);

        inputs->processInput(deltaTime);
        
        scene.update(deltaTime);
        scene.draw(shaderID, camera->getProjectionMatrix() * camera->getViewMatrix());

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
