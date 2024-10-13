#include "traffic_controller.h"

int main() {
    TrafficController controller;
    controller.startSimulation();

    // Keep the program running indefinitely until user interruption
    std::cout << "Press Ctrl+C to stop the simulation." << std::endl;
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Keep the main thread alive
    }
    return 0;
}
