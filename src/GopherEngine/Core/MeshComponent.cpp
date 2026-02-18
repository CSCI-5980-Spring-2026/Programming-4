#include <GopherEngine/Core/MeshComponent.hpp>
using namespace GopherEngine;

// We will eventually remove these when we add draw functionality to the material
#include <glm/gtc/type_ptr.hpp> // value_ptr function to convert glm types to pointer for OpenGL
#include <SFML/OpenGL.hpp>

void MeshComponent::set_mesh(shared_ptr<Mesh> mesh) {
    mesh_ = std::move(mesh);
}

shared_ptr<Mesh> MeshComponent::get_mesh() const {
    return mesh_;
}

void MeshComponent::draw(const glm::mat4 &world_matrix) {

    if (!mesh_ || mesh_->vertices_.empty())
        return;

    // Enable the position vertex component
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(
        3,                              // x,y,z
        GL_FLOAT,                       // component type
        sizeof(glm::vec3),              // stride (handles possible padding/alignment)
        value_ptr(mesh_->vertices_[0])  // pointer to first float
    );

    // Disable normal, color, and texture coordinate vertex components
    // We have not added shaders yet, so we will not use these attributes
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);

    // Set the modelview matrix to the identity matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Load the model matrix into OpenGL
    glLoadMatrixf(glm::value_ptr(world_matrix));

    // Submit the geometry to the GPU
    // We have not implemented indices yet, so treat the vertices as a list of triangles
    glDrawArrays(GL_TRIANGLES, 0, mesh_->vertices_.size());

}