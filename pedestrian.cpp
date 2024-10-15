#include "pedestrian.h"
#include "traffic_light.h"
#include <omp.h> // Include OpenMP

Pedestrian::Pedestrian(int id, TrafficLight* light, std::mutex& mtx) : id(id), light(light), mtx(mtx) {}

void Pedestrian::start() {
    #pragma omp parallel // Parallelize pedestrian behavior using OpenMP
    {
        std::thread(&Pedestrian::requestCrossing, this).detach(); // Start the requestCrossing function in a new thread
    }
}

void Pedestrian::requestCrossing() {
    while (true) {
        {
            std::lock_guard<std::mutex> lock(mtx); // Lock for console output
            std::cout << "Pedestrian " << id << " is requesting to cross." << std::endl;
        }

        // Simulate waiting for the light to turn red for crossing
        {
            std::lock_guard<std::mutex> lock(mtx); // Lock for console output
            if (light->getColor() == TrafficLight::RED) {
                std::cout << "Pedestrian " << id << " is crossing the street." << std::endl;
            } else {
                std::cout << "Pedestrian " << id << " is waiting for the red light." << std::endl;
            }
        }
        std::this_thread::sleep_for(std::chrono::seconds(5)); // Simulate time between requests
    }
}
