#include <GopherEngine/Core/Scene.hpp>

namespace GopherEngine {

    Scene::Scene() {
        
    }

    Scene::~Scene() {

    }

    void Scene::add_node(shared_ptr<Node> node) {

        nodes_.push_back(node);
        
    }

    shared_ptr<Node> Scene::create_node() {

        shared_ptr<Node> node = make_shared<Node>();
        nodes_.push_back(node);
        return node;

    }

    void Scene::update(float delta_time) {

        for(auto& node: nodes_) {
            node->update(delta_time);
        }

    }

    void Scene::draw() {

        for(auto& node: nodes_) {
            node->update_matrices();
            node->draw();
        }

    }
}