#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MiniGameSystem.generated.h"

USTRUCT(BlueprintType)
struct FMiniGame
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MiniGameName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIsActive;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIsCompleted;

    FMiniGame()
    {
        MiniGameName = "";
        Description = "";
        bIsActive = false;
        bIsCompleted = false;
    }
};

UCLASS()
class MYGAME_API AMiniGameSystem : public AActor
{
    GENERATED_BODY()

public:
    AMiniGameSystem();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    void StartMiniGame(FString MiniGameName);
    void CompleteMiniGame(FString MiniGameName);
    void TrackMiniGameProgress(FString MiniGameName, int32 Progress);

private:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FMiniGame> MiniGames;

    FMiniGame* FindMiniGame(FString MiniGameName);
};
