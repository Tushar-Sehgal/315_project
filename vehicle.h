#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <fstream>

class TrafficLight; // Forward declaration

class Vehicle {
public:
    Vehicle(int id, TrafficLight* light, std::mutex& mtx);
    ~Vehicle(); // Declare destructor
    void start(); // Declare start method

private:
    int id;
    TrafficLight* light;
    std::mutex& mtx; // Reference to mutex for synchronization
    void approachLight(); // Private method

    std::ofstream logFile; // Log file stream
};

#endif // VEHICLE_H
