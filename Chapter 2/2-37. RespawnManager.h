#pragma once


#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RespawnManager.generated.h"

UCLASS()
class MYGAME_API URespawnManager : public UObject
{
GENERATED_BODY()

public:
URespawnManager();

// Function to set a specific respawn point location
UFUNCTION(BlueprintCallable)
void SetRespawnPoint(FVector RespawnLocation);

// Function to activate a respawn point for player use
UFUNCTION(BlueprintCallable)
void ActivateRespawnPoint();

// Function to deactivate a respawn point temporarily or permanently
UFUNCTION(BlueprintCallable)
void DeactivateRespawnPoint();

protected:
// Stores the current respawn location
FVector CurrentRespawnLocation;

// Timer handle to manage the reactivation of a respawn point
FTimerHandle RespawnTimerHandle;

// Respawn point's active status
bool bIsRespawnActive;

// Function to reset the respawn point to active after a delay
void ResetRespawnPoint();
};
