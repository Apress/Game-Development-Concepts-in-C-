#include "RespawnManager.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "TimerManager.h"

URespawnManager::URespawnManager()
{
    // Initialize default values
    bIsRespawnActive = true;
}

void URespawnManager::SetRespawnPoint(FVector RespawnLocation)
{
    // Set the player's current location as the respawn location
    CurrentRespawnLocation = RespawnLocation;

    // Optionally, trigger other logic like updating a UI or activating a checkpoint
}

void URespawnManager::ActivateRespawnPoint()
{
    if (!bIsRespawnActive)
    {
        // Logic to activate the respawn point if it was previously deactivated
        bIsRespawnActive = true;
        // Optionally, notify other systems about the activation
    }
}

void URespawnManager::DeactivateRespawnPoint()
{
    if (bIsRespawnActive)
    {
        // Deactivate the respawn point temporarily
        bIsRespawnActive = false;

        // Optionally, add logic to notify the player or gameplay systems

        // Set a timer to reset the respawn point after a delay (e.g., 5 seconds)
        GetWorld()->GetTimerManager().SetTimer(RespawnTimerHandle, this, &URespawnManager::ResetRespawnPoint, 5.0f, false);
    }
}

void URespawnManager::ResetRespawnPoint()
{
    // Reset the respawn point to active after the delay
    bIsRespawnActive = true;

    // Optionally, add logic to notify players about respawn point reactivation
}
