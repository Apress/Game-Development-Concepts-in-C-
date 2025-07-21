#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>

class Skybox {
public:
    Skybox(const std::vector<std::string>& faces);
    void Draw(const glm::mat4& view, const glm::mat4& projection);
    void Update(float deltaTime);
    
private:
    GLuint skyboxTexture;
    GLuint VAO, VBO;
    float timeOfDay;
};
