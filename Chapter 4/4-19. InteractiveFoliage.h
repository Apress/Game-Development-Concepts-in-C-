#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

class InteractiveFoliage {
public:
    InteractiveFoliage();
    void UpdateFoliage(const glm::vec3& playerPosition, float windStrength);
    void RenderFoliage();

private:
    std::vector<glm::vec3> foliagePositions;
    GLuint foliageShader;
};
