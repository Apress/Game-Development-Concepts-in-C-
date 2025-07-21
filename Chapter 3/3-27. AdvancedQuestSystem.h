#pragma once

#include "CoreMinimal.h"
#include "QuestSystem.h"
#include "AdvancedQuestSystem.generated.h"

UCLASS()
class MYGAME_API AAdvancedQuestSystem : public AQuestSystem
{
    GENERATED_BODY()

public:
    AAdvancedQuestSystem();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    void BranchQuest(FString QuestName, FString NewQuestName);
    void SetQuestDependency(FString QuestName, FString DependentQuestName);

private:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<FString, FString> QuestDependencies;
};
