#include <GopherEngine/Core/MeshComponent.hpp>
using namespace GopherEngine;

// We will eventually remove these when we add draw functionality to the material
#include <glm/gtc/type_ptr.hpp> // value_ptr function to convert glm types to pointer for OpenGL
#include <SFML/OpenGL.hpp>
#include <array>


void MeshComponent::initialize(Transform& transform) {
     transform.position_.z = -2.f; 
}

void MeshComponent::update(Transform& transform, float delta_time) {
    // Rotate the node around the Y axis at a constant speed of 45 degrees per second
    auto frame_rotation = glm::angleAxis(
        delta_time * glm::radians(45.f), 
        glm::vec3(0.f, 1.f, 0.f)
    );
    transform.rotation_ =  frame_rotation * transform.rotation_;
}

void MeshComponent::draw(const glm::mat4 &world_matrix) {
    // Define a 3D cube (6 faces made of 2 triangles)
        constexpr std::array<GLfloat, 180> cube =
        {
            -.5f, -.5f, -.5f,
            -.5f,  .5f, -.5f,
            -.5f, -.5f,  .5f,
            -.5f, -.5f,  .5f, 
            -.5f,  .5f, -.5f, 
            -.5f,  .5f,  .5f,

            .5f, -.5f, -.5f,
            .5f,  .5f, -.5f,
            .5f, -.5f,  .5f,
            .5f, -.5f,  .5f,
            .5f,  .5f, -.5f,
            .5f,  .5f,  .5f,

            -.5f, -.5f, -.5f,
            .5f, -.5f, -.5f,
            -.5f, -.5f,  .5f,
            -.5f, -.5f,  .5f, 
            .5f, -.5f, -.5f,
            .5f, -.5f,  .5f,

            -.5f,  .5f, -.5f,
            .5f,  .5f, -.5f,
            -.5f,  .5f,  .5f,
            -.5f,  .5f,  .5f,
            .5f,  .5f, -.5f,
            .5f,  .5f,  .5f,

            -.5f, -.5f, -.5f, 
            .5f, -.5f, -.5f,
            -.5f,  .5f, -.5f,
            -.5f,  .5f, -.5f, 
            .5f, -.5f, -.5f,
            .5f,  .5f, -.5f,

            -.5f, -.5f,  .5f, 
            .5f, -.5f,  .5f,
            -.5f,  .5f,  .5f,
            -.5f,  .5f,  .5f,
            .5f, -.5f,  .5f, 
            .5f,  .5f,  .5f
        };

        // Enable the position vertex component
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 3 * sizeof(GLfloat), cube.data());

        // Disable normal, color, and texture coordinate vertex components
        // We have not added shaders yet, so we will not use these attributes
        glDisableClientState(GL_NORMAL_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);

        // Set the modelview matrix to the identity matrix
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        // Load the model matrix into OpenGL
        glLoadMatrixf(value_ptr(world_matrix));

        // Draw the cube
        glDrawArrays(GL_TRIANGLES, 0, 36);
}
