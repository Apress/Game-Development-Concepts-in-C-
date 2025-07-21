#include "QuestManager.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

AQuestManager::AQuestManager()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AQuestManager::StartQuest(FString QuestName)
{
    if (!ActiveQuests.Contains(QuestName))
    {
        ActiveQuests.Add(QuestName);
        QuestProgress.Add(QuestName, 0);
        UE_LOG(LogTemp, Warning, TEXT("Quest Started: %s"), *QuestName);
    }
}

void AQuestManager::CompleteQuest(FString QuestName)
{
    if (ActiveQuests.Contains(QuestName))
    {
        ActiveQuests.Remove(QuestName);
        QuestProgress.Remove(QuestName);
        UE_LOG(LogTemp, Warning, TEXT("Quest Completed: %s"), *QuestName);
    }
}

void AQuestManager::UpdateQuestProgress(FString QuestName, int32 Progress)
{
    if (QuestProgress.Contains(QuestName))
    {
        QuestProgress[QuestName] = Progress;
        UE_LOG(LogTemp, Warning, TEXT("Quest Progress Updated: %s - %d%%"), *QuestName, Progress);
    }
}
