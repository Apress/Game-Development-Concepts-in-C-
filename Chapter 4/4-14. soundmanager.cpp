#include "SoundManager.h"

SoundManager::SoundManager() : volume(128) {
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
}

SoundManager::~SoundManager() {
    for (auto& pair : sounds) {
        Mix_FreeChunk(pair.second);
    }
    Mix_CloseAudio();
}

void SoundManager::LoadSound(const std::string& soundName, const std::string& filePath) {
    Mix_Chunk* sound = Mix_LoadWAV(filePath.c_str());
    if (sound != nullptr) {
        sounds[soundName] = sound;
    }
}

void SoundManager::PlaySound(const std::string& soundName) {
    if (sounds.find(soundName) != sounds.end()) {
        Mix_PlayChannel(-1, sounds[soundName], 0);
    }
}

void SoundManager::SetVolume(int volume) {
    this->volume = volume;
    Mix_Volume(-1, this->volume);
}
