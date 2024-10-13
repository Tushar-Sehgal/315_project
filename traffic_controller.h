#ifndef TRAFFIC_CONTROLLER_H
#define TRAFFIC_CONTROLLER_H

#include "traffic_light.h"
#include "vehicle.h"
#include "pedestrian.h"
#include <vector>
#include <mutex> // Include mutex header

class TrafficController {
public:
    TrafficController();
    void startSimulation();

    std::mutex mtx; // Mutex for console output

private:
    std::vector<TrafficLight*> lights;
    std::vector<Vehicle*> vehicles;
    std::vector<Pedestrian*> pedestrians;
    void setup();
};

#endif // TRAFFIC_CONTROLLER_H
