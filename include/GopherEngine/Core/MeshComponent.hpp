#pragma once

#include <GopherEngine/Core/Component.hpp>
#include <GopherEngine/Resource/Mesh.hpp>
using namespace GopherEngine;

#include <memory>
using namespace std;

class MeshComponent : public Component
{
    public:
        void initialize(Transform& transform) override = 0;
        void update(Transform& transform, float delta_time) override = 0;
        void draw(const glm::mat4 &world_matrix) override;

        void set_mesh(shared_ptr<Mesh> mesh);
        shared_ptr<Mesh> get_mesh() const;

    protected:
        shared_ptr<Mesh> mesh_;
};
