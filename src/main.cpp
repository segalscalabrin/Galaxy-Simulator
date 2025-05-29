#include "include.hpp"
#include "renderEngine/initRenderEngine.hpp"
#include "computeEngine/initComputeEngine.hpp"

int main() 
{
    GLFWwindow* window   = initOpenGL();
    GLuint      shaderID = initShader();
    Camera      camera   = initCamera();
    Scene       scene    = initScene();

    
    // Boucle de rendu
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(shaderID);

        scene.draw(shaderID, camera.getViewProjection());

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
