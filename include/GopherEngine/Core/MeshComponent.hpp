#pragma once

#include <GopherEngine/Core/Transform.hpp>
#include <GopherEngine/Core/Component.hpp>
#include <GopherEngine/Resource/Mesh.hpp>

#include <memory>
using namespace std;

namespace GopherEngine
{
    class MeshComponent : public Component
    {
        public:
            void initialize(Transform& transform) override;
            void update(Transform& transform, float delta_time) override;
            void draw(const glm::mat4 &world_matrix) override;

        protected:
            shared_ptr<Mesh> mesh_;
    };
}