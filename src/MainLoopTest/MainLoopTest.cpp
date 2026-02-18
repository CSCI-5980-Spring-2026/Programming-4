/* Programming 4: Components, Meshes, and Geometry Primitives
 * CSCI 5980, Spring 2026, University of Minnesota
 * Instructor: Evan Suma Rosenberg <suma@umn.edu>
 * License: Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International
 */ 

#include <GopherEngine/Core/MainLoop.hpp>
#include <GopherEngine/Core/MeshComponent.hpp>
using namespace GopherEngine;

#include <iostream>
using namespace std;

// A simple subclass of MainLoop to test that the main loop is working
// and the window, scene, and node classes are functioning correctly
class MainLoopTest: public MainLoop
{
	public:
		// Constructor and destructor
		MainLoopTest();
		~MainLoopTest();

	private:

		// Override the pure virtual functions from MainLoop
		void initialize() override;
		void update(float delta_time) override;
};


MainLoopTest::MainLoopTest() {

}

MainLoopTest::~MainLoopTest() {

}

void MainLoopTest::initialize() {

	window_.set_title("CSCI 5980 Programming 4");

	// Create a single node in the scene to test that the update and draw functions are working
	shared_ptr<Node> node = scene_->create_node();

	node->add_component(make_shared<MeshComponent>());
}

void MainLoopTest::update(float delta_time) {

}

int main()
{
	// Create an instance of the MainLoop subclass and start the main game loop
	MainLoopTest app;
	return app.run();
}