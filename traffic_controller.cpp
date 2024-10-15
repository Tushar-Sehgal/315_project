#include "traffic_controller.h"
#include <omp.h> // Include OpenMP

TrafficController::TrafficController() {
    setup();
}

void TrafficController::setup() {
    // Create traffic lights (no parallelism needed here)
    for (int i = 0; i < 3; ++i) {
        lights.push_back(new TrafficLight(i));
    }

    // Create vehicles and pedestrians in parallel using OpenMP
    #pragma omp parallel for
    for (int i = 0; i < 5; ++i) {
        vehicles.push_back(new Vehicle(i, lights[i % 3], mtx)); // Pass mutex reference
        pedestrians.push_back(new Pedestrian(i, lights[i % 3], mtx)); // Pass mutex reference
    }
}

void TrafficController::startSimulation() {
    // Start traffic lights
    for (auto light : lights) {
        light->start();
    }

    // Start vehicles
    #pragma omp parallel for
    for (auto vehicle : vehicles) {
        vehicle->start();
    }

    // Start pedestrians
    #pragma omp parallel for
    for (auto pedestrian : pedestrians) {
        pedestrian->start();
    }

    // Let the simulation run for a certain period (e.g., 30 seconds)
    std::this_thread::sleep_for(std::chrono::seconds(30));
}
