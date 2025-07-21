#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MultiplayerArena.generated.h"

UCLASS()
class MYGAME_API AMultiplayerArena : public AActor
{
    GENERATED_BODY()

public:
    AMultiplayerArena();

    UFUNCTION(BlueprintCallable, Category = "Arena")
    void SetupArena();

    UFUNCTION(BlueprintCallable, Category = "Arena")
    void SpawnPlayers();
    
    UFUNCTION(BlueprintCallable, Category = "Arena")
    void PlacePowerUps();

private:
    TArray<FVector> SpawnLocations;
    TArray<FVector> PowerUpLocations;
};

