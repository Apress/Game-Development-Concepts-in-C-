#include "InteractiveFoliage.h"
#include <glm/gtc/matrix_transform.hpp>

InteractiveFoliage::InteractiveFoliage() {
    // Load and compile foliage shader
    foliageShader = glCreateProgram();
    // Initialize foliage positions
}

void InteractiveFoliage::UpdateFoliage(const glm::vec3& playerPosition, float windStrength) {
    for (auto& pos : foliagePositions) {
        float distance = glm::length(playerPosition - pos);
        if (distance < 1.0f) {
            // Bend foliage away from the player
            pos += glm::normalize(pos - playerPosition) * 0.1f;
        }
        // Apply wind effect
        pos.y += glm::sin(glfwGetTime() * windStrength) * 0.05f;
    }
}

void InteractiveFoliage::RenderFoliage() {
    glUseProgram(foliageShader);
    for (const auto& pos : foliagePositions) {
        // Render each foliage instance at the updated position
    }
}
