#include "MiniGameSystem.h"

AMiniGameSystem::AMiniGameSystem()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AMiniGameSystem::BeginPlay()
{
    Super::BeginPlay();
}

void AMiniGameSystem::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AMiniGameSystem::StartMiniGame(FString MiniGameName)
{
    FMiniGame* MiniGame = FindMiniGame(MiniGameName);
    if (MiniGame && !MiniGame->bIsActive && !MiniGame->bIsCompleted)
    {
        MiniGame->bIsActive = true;
        // Additional logic for starting the mini-game (e.g., transitioning to mini-game mode)
    }
}

void AMiniGameSystem::CompleteMiniGame(FString MiniGameName)
{
    FMiniGame* MiniGame = FindMiniGame(MiniGameName);
    if (MiniGame && MiniGame->bIsActive && !MiniGame->bIsCompleted)
    {
        MiniGame->bIsCompleted = true;
        MiniGame->bIsActive = false;
        // Additional logic for completing the mini-game (e.g., awarding rewards, transitioning back to main game)
    }
}

void AMiniGameSystem::TrackMiniGameProgress(FString MiniGameName, int32 Progress)
{
    FMiniGame* MiniGame = FindMiniGame(MiniGameName);
    if (MiniGame && MiniGame->bIsActive && !MiniGame->bIsCompleted)
    {
        // Implement progress tracking logic here (e.g., updating objectives)
    }
}

FMiniGame* AMiniGameSystem::FindMiniGame(FString MiniGameName)
{
    for (FMiniGame& MiniGame : MiniGames)
    {
        if (MiniGame.MiniGameName == MiniGameName)
        {
            return &MiniGame;
        }
    }
    return nullptr;
}
