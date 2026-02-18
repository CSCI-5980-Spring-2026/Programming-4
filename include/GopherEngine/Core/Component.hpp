#pragma once

#include <GopherEngine/Core/Transform.hpp>

#include <glm/glm.hpp> // general glm header for basic types like vec3 and mat4
#include <glm/gtc/quaternion.hpp> // glm quaternion functions

namespace GopherEngine
{
    class Component
    {
        public:
            virtual ~Component() = default;
            virtual void initialize(Transform& transform) = 0;
            virtual void update(Transform& transform, float delta_time) = 0;
            virtual void draw(const glm::mat4 &world_matrix) = 0;
    };
}