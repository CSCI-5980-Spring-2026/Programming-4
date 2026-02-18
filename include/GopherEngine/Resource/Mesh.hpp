#pragma once

#include <glm/glm.hpp>
#include <vector>

using namespace std;

namespace GopherEngine {
    struct Mesh {
        vector<glm::vec3> vertices_;
        vector<glm::vec3> normals_;
        vector<glm::vec2> uvs_;
        vector<unsigned int> indices_;
    };
}