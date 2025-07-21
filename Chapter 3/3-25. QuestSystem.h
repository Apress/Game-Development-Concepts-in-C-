#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuestSystem.generated.h"

USTRUCT(BlueprintType)
struct FQuest
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString QuestName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIsActive;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIsCompleted;

    FQuest()
    {
        QuestName = "";
        Description = "";
        bIsActive = false;
        bIsCompleted = false;
    }
};

UCLASS()
class MYGAME_API AQuestSystem : public AActor
{
    GENERATED_BODY()

public:
    AQuestSystem();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    void ActivateQuest(FString QuestName);
    void CompleteQuest(FString QuestName);
    void TrackQuestProgress(FString QuestName, int32 Progress);

private:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FQuest> Quests;

    FQuest* FindQuest(FString QuestName);
};
