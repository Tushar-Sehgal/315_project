#include "traffic_light.h"

TrafficLight::TrafficLight(int id) : id(id), currentColor(RED) {}

void TrafficLight::start() {
    std::thread(&TrafficLight::changeLight, this).detach();
}

TrafficLight::Color TrafficLight::getColor() {
    return currentColor;
}

void TrafficLight::changeLight() {
    while (true) {
        currentColor = GREEN;
        std::cout << "Traffic Light " << id << " is GREEN" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(10)); // Green light duration

        currentColor = YELLOW;
        std::cout << "Traffic Light " << id << " is YELLOW" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));  // Yellow light duration

        currentColor = RED;
        std::cout << "Traffic Light " << id << " is RED" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(10)); // Red light duration
    }
}