#include <GopherEngine/Core/MainLoop.hpp>
#include <GopherEngine/Renderer/Renderer.hpp>

#include <iostream>
using namespace std;

namespace GopherEngine {
    MainLoop::MainLoop()
    {
        scene_ = make_shared<Scene>();
    }

    MainLoop::~MainLoop()
    {
    }

    int MainLoop::run()
    {
        initialize();

        window_.create_window();

        if(!window_.set_active(true)) {
            cerr << "Failed to set window to active" << endl;
            return EXIT_FAILURE;
        }

        renderer_.initialize(window_.get_width(), window_.get_height());

        // Reset the clock to start measuring time from the beginning of the main loop
        clock_.reset();

        while(window_.is_open())
        {
            window_.handle_events();

            if(window_.get_dirty()) {
                renderer_.resize_viewport(window_.get_width(), window_.get_height());
                window_.set_dirty(false);
            }

            float delta_time = clock_.delta_time();

            update(delta_time);
            scene_->update(delta_time);

            renderer_.draw(*scene_);
            window_.display();
        }
        
        return EXIT_SUCCESS;
    }
}

