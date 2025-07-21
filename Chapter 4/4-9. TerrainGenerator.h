#pragma once
#include <vector>

class TerrainGenerator {
public:
    TerrainGenerator(int width, int height);
    void GenerateTerrain();
    std::vector<std::vector<float>> GetHeightmap() const;

private:
    int m_width;
    int m_height;
    std::vector<std::vector<float>> m_heightmap;

    void ApplyNoise();
    void ErodeTerrain();
};
