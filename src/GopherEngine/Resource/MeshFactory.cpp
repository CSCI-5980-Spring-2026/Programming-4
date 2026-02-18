#include <GopherEngine/Resource/MeshFactory.hpp>
using namespace GopherEngine;

shared_ptr<Mesh> MeshFactory::create_cube() {
    auto mesh = make_shared<Mesh>();

    // Define the vertices of a unit cube
    mesh->vertices_ = {
        {-.5f, -.5f, -.5f},
        {-.5f,  .5f, -.5f},
        {-.5f, -.5f,  .5f},
        {-.5f, -.5f,  .5f}, 
        {-.5f,  .5f, -.5f}, 
        {-.5f,  .5f,  .5f},

        {.5f, -.5f, -.5f},
        {.5f,  .5f, -.5f},
        {.5f, -.5f,  .5f},
        {.5f, -.5f,  .5f},
        {.5f,  .5f, -.5f},
        {.5f,  .5f,  .5f},

        {-.5f, -.5f, -.5f},
        {.5f, -.5f, -.5f},
        {-.5f, -.5f,  .5f},
        {-.5f, -.5f,  .5f}, 
        {.5f, -.5f, -.5f},
        {.5f, -.5f,  .5f},

        {-.5f,  .5f, -.5f},
        {.5f,  .5f, -.5f},
        {-.5f,  .5f,  .5f},
        {-.5f,  .5f,  .5f},
        {.5f,  .5f, -.5f},
        {.5f,  .5f,  .5f},

        {-.5f, -.5f, -.5f}, 
        {.5f, -.5f, -.5f},
        {-.5f,  .5f, -.5f},
        {-.5f,  .5f, -.5f}, 
        {.5f, -.5f, -.5f},
        {.5f,  .5f, -.5f},

        {-.5f, -.5f,  .5f}, 
        {.5f, -.5f,  .5f},
        {-.5f,  .5f,  .5f},
        {-.5f,  .5f,  .5f},
        {.5f, -.5f,  .5f}, 
        {.5f,  .5f,  .5f}
    };

    return mesh;
}