#include <random>
#include "vehicle.h"
#include "traffic_light.h"

Vehicle::Vehicle(int id, TrafficLight* light, std::mutex& mtx) : id(id), light(light), mtx(mtx) {
    logFile.open("traffic_log.txt", std::ios::app); // Open log file in append mode
}

Vehicle::~Vehicle() {
    if (logFile.is_open()) {
        logFile.close(); // Close log file in the destructor
    }
}

void Vehicle::start() {
    std::thread(&Vehicle::approachLight, this).detach(); // Start the approachLight function in a new thread
}

void Vehicle::approachLight() {
    while (true) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            std::cout << "Vehicle " << id << " is approaching traffic light." << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));

        {
            std::lock_guard<std::mutex> lock(mtx);
            if (light->getColor() == TrafficLight::GREEN) {
                std::cout << "Vehicle " << id << " is passing through the green light." << std::endl;
            } else if (light->getColor() == TrafficLight::RED) {
                // Randomly decide whether to cross at red light (for testing)
                std::random_device rd; // Seed for random number generation
                std::mt19937 gen(rd()); // Random number generator
                std::uniform_int_distribution<> dis(1, 10); // Generate numbers between 1 and 10
                int chance = dis(gen);
                if (chance <= 3) { // 30% chance to cross at red light
                    logFile << "Vehicle " << id << " crossed the road at a red light." << std::endl;
                    std::cout << "Vehicle " << id << " crossed the road at a red light!" << std::endl;
                } else {
                    std::cout << "Vehicle " << id << " is waiting at the red light." << std::endl;
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::seconds(5)); // Simulate time between vehicles
    }
}