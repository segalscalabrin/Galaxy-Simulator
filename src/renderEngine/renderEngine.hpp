#pragma once

#include "include.hpp"

#include "renderEngine/camera.hpp"
#include "renderEngine/shaders.hpp"
#include "renderEngine/shapes.hpp"
#include "renderEngine/inputs.hpp"

#include "computeEngine/scene.hpp"


class RenderEngine
{
    private:
        GLFWwindow* m_window;
        std::shared_ptr<SimulationOptions>  m_simOptions;
        std::shared_ptr<Camera>             m_camera;
        std::shared_ptr<InputController>    m_inputs;
        std::shared_ptr<Shapes>             m_shapes;
        std::shared_ptr<Shaders>            m_shaders;

        GLFWwindow* initOpenGL();
        void initGraphicsOptions();

    public:
        RenderEngine();
        ~RenderEngine();

        void run(std::shared_ptr<Scene> scene);
};
