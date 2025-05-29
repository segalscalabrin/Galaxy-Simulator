#include "shapes.hpp"

// -----------------------------------------------------
// -----------------------------------------------------
//                      SPHERE
// -----------------------------------------------------
// -----------------------------------------------------

Sphere::Sphere() {
    createBaseIcosphere();
    uploadToOpenGL();
}


void Sphere::createBaseIcosphere() {
    const float X=.525731112119133606f;
    const float Z=.850650808352039932f;
    const float N=0.f;

    vertexList = {
        {-X,N,Z}, {X,N,Z}, {-X,N,-Z}, {X,N,-Z},
        {N,Z,X}, {N,Z,-X}, {N,-Z,X}, {N,-Z,-X},
        {Z,X,N}, {-Z,X, N}, {Z,-X,N}, {-Z,-X, N}
    };

    indexList = {
        0,4,1,  0,9,4,  9,5,4,  4,5,8,  4,8,1,
        8,10,1, 8,3,10, 5,3,8,  5,2,3,  2,7,3,
        7,10,3, 7,6,10, 7,11,6, 11,0,6, 0,1,6,
        6,1,10, 9,0,11, 9,11,2, 9,2,5,  7,2,11
    };


    for(glm::vec3& vertex : vertexList) {
        vertex = glm::normalize(vertex);
    }
}


void Sphere::uploadToOpenGL() {
    indexCount = indexList.size();

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertexList.size() * sizeof(glm::vec3), vertexList.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexList.size() * sizeof(unsigned int), indexList.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
}


void Sphere::draw(const glm::vec3 position, float radius, const glm::vec4 color, GLuint shaderID, const glm::mat4 viewProj) const {
    glm::mat4 model = glm::translate(glm::mat4(1.0f), position);
    model = glm::scale(model, glm::vec3(radius));
    glm::mat4 MVP = viewProj * model;

    glUseProgram(shaderID);
    glUniformMatrix4fv(glGetUniformLocation(shaderID, "MVP"), 1, GL_FALSE, glm::value_ptr(MVP));
    glUniform4fv(glGetUniformLocation(shaderID, "inputColor"), 1, glm::value_ptr(color));

    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}



// -----------------------------------------------------
// -----------------------------------------------------
//                      CUBE
// -----------------------------------------------------
// -----------------------------------------------------