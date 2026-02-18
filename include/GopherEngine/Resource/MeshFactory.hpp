#pragma once

#include <GopherEngine/Resource/Mesh.hpp>
using namespace GopherEngine;

#include <memory>
using namespace std;

namespace GopherEngine {

    class MeshFactory {
        public:
            static shared_ptr<Mesh> create_cube();
    };

} 