#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuestManager.generated.h"

UCLASS()
class MYGAME_API AQuestManager : public AActor
{
    GENERATED_BODY()

public:
    AQuestManager();

    UFUNCTION(BlueprintCallable, Category = "Quest")
    void StartQuest(FString QuestName);

    UFUNCTION(BlueprintCallable, Category = "Quest")
    void CompleteQuest(FString QuestName);

    UFUNCTION(BlueprintCallable, Category = "Quest")
    void UpdateQuestProgress(FString QuestName, int32 Progress);

private:
    TMap<FString, int32> QuestProgress;
    TArray<FString> ActiveQuests;
};
