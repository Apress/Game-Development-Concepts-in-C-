#include "TerrainTexture.h"
#include <stb_image.h>

TerrainTexture::TerrainTexture(const std::vector<std::string>& textures) {
    glGenTextures(textures.size(), textureIDs.data());
    for (size_t i = 0; i < textures.size(); i++) {
        int width, height, nrChannels;
        unsigned char* data = stbi_load(textures[i].c_str(), &width, &height, &nrChannels, 0);
        if (data) {
            glBindTexture(GL_TEXTURE_2D, textureIDs[i]);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            stbi_image_free(data);
        }
    }
}

void TerrainTexture::ApplyTexture(const glm::vec3& position) {
    // Determine which texture to apply based on position
    // Set shader uniforms and bind the correct texture
}
