#include "include.hpp"

#include "renderEngine/renderEngine.hpp"

int main() 
{
    std::unique_ptr<RenderEngine> renderEngine = std::make_unique<RenderEngine>();
    std::shared_ptr<Scene> scene = std::make_shared<Scene>();

    renderEngine->run(scene);

    return 0;
}
