// This file is not mine its from https://www.opengl-tutorial.org/fr/beginners-tutorials/tutorial-2-the-first-triangle/

#pragma once 

#include "include.hpp"


GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);


class Shaders
{
    private:
        GLuint m_shaderId;

    public:
        Shaders();
        ~Shaders();

        void loadShaders(const char * vertex_file_path,const char * fragment_file_path);

        GLuint getShaders() const; 
};