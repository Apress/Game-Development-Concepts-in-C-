#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>

class TerrainTexture {
public:
    TerrainTexture(const std::vector<std::string>& textures);
    void ApplyTexture(const glm::vec3& position);
    
private:
    std::vector<GLuint> textureIDs;
    GLuint shaderProgram;
};
