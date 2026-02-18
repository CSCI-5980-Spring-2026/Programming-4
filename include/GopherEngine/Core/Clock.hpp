#pragma once

#include <chrono>
using namespace std;

namespace GopherEngine
{
    class Clock
    {
        public:
            Clock();
            ~Clock();
            void reset();
            float delta_time();
            float get_elapsed_time() const;

        private:
            chrono::time_point<chrono::high_resolution_clock> start_ticks;
            chrono::time_point<chrono::high_resolution_clock> last_ticks;
    };
}