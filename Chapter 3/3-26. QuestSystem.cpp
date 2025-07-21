#include "QuestSystem.h"

AQuestSystem::AQuestSystem()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AQuestSystem::BeginPlay()
{
    Super::BeginPlay();
}

void AQuestSystem::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AQuestSystem::ActivateQuest(FString QuestName)
{
    FQuest* Quest = FindQuest(QuestName);
    if (Quest && !Quest->bIsActive && !Quest->bIsCompleted)
    {
        Quest->bIsActive = true;
        // Additional logic for activating the quest (e.g., displaying quest log)
    }
}

void AQuestSystem::CompleteQuest(FString QuestName)
{
    FQuest* Quest = FindQuest(QuestName);
    if (Quest && Quest->bIsActive && !Quest->bIsCompleted)
    {
        Quest->bIsCompleted = true;
        Quest->bIsActive = false;
        // Additional logic for completing the quest (e.g., awarding rewards)
    }
}

void AQuestSystem::TrackQuestProgress(FString QuestName, int32 Progress)
{
    FQuest* Quest = FindQuest(QuestName);
    if (Quest && Quest->bIsActive && !Quest->bIsCompleted)
    {
        // Implement progress tracking logic here (e.g., updating objectives)
    }
}

FQuest* AQuestSystem::FindQuest(FString QuestName)
{
    for (FQuest& Quest : Quests)
    {
        if (Quest.QuestName == QuestName)
        {
            return &Quest;
        }
    }
    return nullptr;
}
