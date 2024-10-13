#ifndef PEDESTRIAN_H
#define PEDESTRIAN_H

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

class TrafficLight; // Forward declaration

class Pedestrian {
public:
    Pedestrian(int id, TrafficLight* light, std::mutex& mtx); // Constructor
    void start(); // Declare start method

private:
    int id;
    TrafficLight* light;
    std::mutex& mtx; // Reference to mutex for synchronization
    void requestCrossing(); // Private method
};

#endif // PEDESTRIAN_H
