#pragma once

#include <GopherEngine/Core/Component.hpp>
#include <GopherEngine/Core/Transform.hpp>

#include <glm/glm.hpp> // general glm header for basic types like vec3 and mat4
#include <glm/gtc/quaternion.hpp> // glm quaternion functions

#include <memory> // for std::shared_ptr
#include <vector> // for std::vector
#include <atomic> // for the atomic id counter
using namespace std;

namespace GopherEngine
{
    class Node
    {
        public:
            Node();
            ~Node();
            void update(float delta_time);
            void update_matrices();
            void draw();

            void add_component(shared_ptr<Component> component);

        private:
            uint32_t id_;
            Transform transform_;
            glm::mat4 local_matrix_{1.f}; 
            glm::mat4 world_matrix_{1.f}; 

            vector<shared_ptr<Component>> components_;

            // Static member variable declaration for the id counter
            static std::atomic<std::uint32_t> id_counter_;
    };
}