#include <GopherEngine/Renderer/Renderer.hpp>

#include <SFML/OpenGL.hpp>
#include <array>

namespace GopherEngine {
    Renderer::Renderer()
    {}

    Renderer::~Renderer()
    {}

    void Renderer::initialize(unsigned int width, unsigned int height)
    {
        // Graphics initialization
        glEnable(GL_DEPTH_TEST);
        glDepthMask(GL_TRUE);
        glClearDepth(1.f);
        glDisable(GL_LIGHTING);

        resize_viewport(width, height);
    }

    void Renderer::resize_viewport(unsigned int width, unsigned int height) {
        glViewport(0, 0, static_cast<GLsizei>(width), static_cast<GLsizei>(height));
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        const GLfloat new_ratio =  static_cast<float>(width) / static_cast<float>(height);
        glFrustum(-new_ratio, new_ratio, -1.f, 1.f, 1.f, 500.f);
    }

    void Renderer::draw(Scene &scene) {

        // Clear the buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        scene.draw();
    }
}