#pragma once

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

        private:
            uint32_t id_;
            glm::vec3 position_{0.f, 0.f, 0.f};
            glm::quat rotation_{1.f, 0.f, 0.f, 0.f};
            glm::vec3 scale_{1.f, 1.f, 1.f};
            glm::mat4 local_matrix_{1.f}; 
            glm::mat4 world_matrix_{1.f}; 

            // Static member variable declaration for the id counter
            static std::atomic<std::uint32_t> id_counter_;
    };
}