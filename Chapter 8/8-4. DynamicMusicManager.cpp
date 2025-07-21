 #include "DynamicMusicManager.h"
#include "Kismet/GameplayStatics.h"
 
ADynamicMusicManager::ADynamicMusicManager()
{
    PrimaryActorTick.bCanEverTick = true;
    CurrentMusicState = ESoundtrackState::Exploration; // Default state
}
 
void ADynamicMusicManager::BeginPlay()
{
    Super::BeginPlay();
    PlayMusic(ExplorationMusic); // Start with exploration music
}
 
void ADynamicMusicManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    // Add logic here to detect game state changes and call ChangeMusicState()
}
 
void ADynamicMusicManager::ChangeMusicState(ESoundtrackState NewState)
{
    if (NewState != CurrentMusicState)
    {
        CurrentMusicState = NewState;
 
        switch (NewState)
        {
        case ESoundtrackState::Exploration:
            PlayMusic(ExplorationMusic);
            break;
        case ESoundtrackState::Combat:
            PlayMusic(CombatMusic);
            break;
        case ESoundtrackState::Boss:
            PlayMusic(BossMusic);
            break;
        default:
            break;
        }
    }
}
 
void ADynamicMusicManager::PlayMusic(USoundBase* NewMusic)
{
    if (NewMusic)
    {
        UGameplayStatics::PlaySound2D(this, NewMusic);
    }
}
