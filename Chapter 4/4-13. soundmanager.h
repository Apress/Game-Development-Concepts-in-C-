#pragma once

#include <map>
#include <string>
#include <SDL_mixer.h>

class SoundManager {
public:
    SoundManager();
    ~SoundManager();
    void LoadSound(const std::string& soundName, const std::string& filePath);
    void PlaySound(const std::string& soundName);
    void SetVolume(int volume);
    
private:
    std::map<std::string, Mix_Chunk*> sounds;
    int volume;
};
