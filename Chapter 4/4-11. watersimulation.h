#pragma once

#include <vector>
#include "Vector3.h"

class WaterSimulation {
public:
    WaterSimulation(int width, int height);
    void Update(float deltaTime);
    void Render();
    
private:
    int width;
    int height;
    std::vector<Vector3> waterParticles;
    
    void GenerateWaves();
    void ApplyFluidDynamics();
};
