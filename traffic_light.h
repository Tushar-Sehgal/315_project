#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include <iostream>
#include <thread>
#include <chrono>

class TrafficLight {
public:
    enum Color { RED, GREEN, YELLOW };
    TrafficLight(int id);
    void start();
    Color getColor();

private:
    Color currentColor;
    int id;
    void changeLight();
};

#endif // TRAFFIC_LIGHT_H
