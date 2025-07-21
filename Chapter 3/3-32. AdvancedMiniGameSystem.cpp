#include "AdvancedMiniGameSystem.h"

AAdvancedMiniGameSystem::AAdvancedMiniGameSystem()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AAdvancedMiniGameSystem::BeginPlay()
{
    Super::BeginPlay();
}

void AAdvancedMiniGameSystem::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AAdvancedMiniGameSystem::AdjustDifficulty(FString MiniGameName, int32 DifficultyLevel)
{
    if (FindMiniGame(MiniGameName))
    {
        MiniGameDifficulties.Add(MiniGameName, DifficultyLevel);
        // Additional logic for adjusting the mini-game difficulty
    }
}

void AAdvancedMiniGameSystem::SetMiniGameReward(FString MiniGameName, FString Reward)
{
    if (FindMiniGame(MiniGameName))
    {
        MiniGameRewards.Add(MiniGameName, Reward);
        // Additional logic for setting the mini-game reward
    }
}
