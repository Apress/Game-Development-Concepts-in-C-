#pragma once

#include "CoreMinimal.h"
#include "MiniGameSystem.h"
#include "AdvancedMiniGameSystem.generated.h"

UCLASS()
class MYGAME_API AAdvancedMiniGameSystem : public AMiniGameSystem
{
    GENERATED_BODY()

public:
    AAdvancedMiniGameSystem();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    void AdjustDifficulty(FString MiniGameName, int32 DifficultyLevel);
    void SetMiniGameReward(FString MiniGameName, FString Reward);

private:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<FString, int32> MiniGameDifficulties;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<FString, FString> MiniGameRewards;
};
