#pragma once

#include <GopherEngine/Core/Transform.hpp>
#include <GopherEngine/Core/Component.hpp>

namespace GopherEngine
{
    class MeshComponent : public Component
    {
        public:
            void initialize(Transform& transform) override;
            void update(Transform& transform, float delta_time) override;
            void draw(const glm::mat4 &world_matrix) override;

        private:
            // Add any member variables you need for the mesh component here
    };
}