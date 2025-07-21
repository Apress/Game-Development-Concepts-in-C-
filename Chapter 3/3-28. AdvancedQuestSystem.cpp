#include "AdvancedQuestSystem.h"

AAdvancedQuestSystem::AAdvancedQuestSystem()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AAdvancedQuestSystem::BeginPlay()
{
    Super::BeginPlay();
}

void AAdvancedQuestSystem::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AAdvancedQuestSystem::BranchQuest(FString QuestName, FString NewQuestName)
{
    FQuest* Quest = FindQuest(QuestName);
    if (Quest && Quest->bIsCompleted)
    {
        ActivateQuest(NewQuestName);
    }
}

void AAdvancedQuestSystem::SetQuestDependency(FString QuestName, FString DependentQuestName)
{
    if (FindQuest(QuestName) && FindQuest(DependentQuestName))
    {
        QuestDependencies.Add(QuestName, DependentQuestName);
    }
}
