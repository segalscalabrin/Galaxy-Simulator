#include "include.hpp"
#include "renderEngine/initOpenGL.hpp"
#include "renderEngine/loadShaders.hpp"
#include "renderEngine/shapeRendering.hpp"
#include "computeEngine/planetCompute.hpp"

int main() 
{
    // Initialize all OpenGL context (glfw and glew)
    GLFWwindow* window = initOpenGL();
    
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);

	// Create and compile our GLSL program from the shaders
	GLuint programID = LoadShaders( "assets/SimpleVertexShader.glsl", "assets/SimpleFragmentShader.glsl" );

    SphereRendering sphereMesh;

    glm::vec3 planetPos = glm::vec3(0.0f, 0.0f, -3.0f); // décalé dans la profondeur
    float planetRadius = 1.0f;
    glm::vec4 planetColor = glm::vec4(0.2f, 0.6f, 1.0f, 1.0f); // bleu

    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 4.f / 3.f, 0.1f, 100.0f);
    glm::mat4 view = glm::lookAt(
        glm::vec3(0, 0, 0),       // position caméra
        glm::vec3(0, 0, -1),      // regarde vers
        glm::vec3(0, 1, 0)        // vecteur "up"
    );
    glm::mat4 viewProj = projection * view;
    
    // Boucle de rendu
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(programID);

        sphereMesh.draw(planetPos, planetRadius, planetColor, programID, viewProj);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    

    // Close all OpenGL context (glfw)
    closeOpenGL(window);

    return 0;
}
