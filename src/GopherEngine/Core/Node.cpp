#include <GopherEngine/Core/Node.hpp>

#include <glm/gtc/matrix_transform.hpp>

// We will eventually remove this when we add draw functionality to the renderer
#include <glm/gtc/type_ptr.hpp> 
#include <SFML/OpenGL.hpp>
#include <array>

namespace GopherEngine {

    // Static member variable initialization for the id counter
    std::atomic<std::uint32_t> Node::id_counter_{0};

    // This constructor incremenents the static id counter and assigns a unique id to each node.
    Node::Node() : id_(id_counter_.fetch_add(1, std::memory_order_relaxed)) {
        position_.z = -2.f; 
    }

    Node::~Node() {

    }

    void Node::update(float delta_time) {

        // Rotate the node around the Y axis at a constant speed of 45 degrees per second
        auto frame_rotation = glm::angleAxis(
            delta_time * glm::radians(45.f), 
            glm::vec3(0.f, 1.f, 0.f)
        );
        rotation_ =  frame_rotation * rotation_;

    }

    void Node::update_matrices() {

        local_matrix_ = glm::mat4(1.f); 
        local_matrix_ = glm::translate(local_matrix_, position_);
        local_matrix_ = local_matrix_ * glm::mat4_cast(rotation_);
        local_matrix_ = glm::scale(local_matrix_, scale_);

        // For now, we will just set the world matrix equal to the local matrix 
        // because we have not implemented parent-child relationships yet.
        world_matrix_ = local_matrix_; 
    }
    
    // In this method, we are still just drawing a simple unit cube for testing purposes.
    // We will eventually move the draw functionality to the renderer, but not in this assignment.
    void Node::draw() {

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
        glLoadMatrixf(value_ptr(world_matrix_));

        // Draw the cube
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }
}