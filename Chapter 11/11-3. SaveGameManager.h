#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SaveGameManager.generated.h"

UCLASS()
class MYGAME_API USaveGameManager : public USaveGame
{
    GENERATED_BODY()

public:
    USaveGameManager();

    UPROPERTY(BlueprintReadWrite, Category = "SaveData")
    int32 PlayerScore;

    UPROPERTY(BlueprintReadWrite, Category = "SaveData")
    FVector PlayerLocation;

    UPROPERTY(BlueprintReadWrite, Category = "SaveData")
    FRotator PlayerRotation;
};
