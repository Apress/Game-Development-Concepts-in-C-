#include "TerrainGenerator.h"
#include <random>

TerrainGenerator::TerrainGenerator(int width, int height)
    : m_width(width), m_height(height) {
    m_heightmap.resize(height, std::vector<float>(width, 0.0f));
}

void TerrainGenerator::GenerateTerrain() {
    ApplyNoise();
    ErodeTerrain();
}

void TerrainGenerator::ApplyNoise() {
    std::default_random_engine generator;
    std::uniform_real_distribution<float> distribution(0.0f, 1.0f);

    for (int y = 0; y < m_height; ++y) {
        for (int x = 0; x < m_width; ++x) {
            m_heightmap[y][x] = distribution(generator); // Simple noise application
        }
    }
}

void TerrainGenerator::ErodeTerrain() {
    // Implement erosion simulation logic here
}

std::vector<std::vector<float>> TerrainGenerator::GetHeightmap() const {
    return m_heightmap;
}
