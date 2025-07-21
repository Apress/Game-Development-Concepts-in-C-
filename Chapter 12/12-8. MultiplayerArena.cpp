#include "MultiplayerArena.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
 
AMultiplayerArena::AMultiplayerArena()
{
    PrimaryActorTick.bCanEverTick = true;
}
 
void AMultiplayerArena::SetupArena()
{
    // Define spawn locations for players
    SpawnLocations.Add(FVector(0, 0, 0)); // Example spawn point
    SpawnLocations.Add(FVector(1000, 1000, 0)); // Another spawn point
}
 
void AMultiplayerArena::SpawnPlayers()
{
    // Example of spawning two players at the defined spawn points
    for (int32 i = 0; i < SpawnLocations.Num(); i++)
    {
        FVector SpawnLocation = SpawnLocations[i];
        AActor* PlayerCharacter = GetWorld()->SpawnActor<AActor>(PlayerClass, SpawnLocation, FRotator::ZeroRotator);
 
        if (PlayerCharacter)
        {
            UE_LOG(LogTemp, Warning, TEXT("Player Spawned at: %s"), *SpawnLocation.ToString());
        }
    }
}
 
void AMultiplayerArena::PlacePowerUps()
{
    // Place power-ups at predefined locations
    for (FVector PowerUpLocation : PowerUpLocations)
    {
        AActor* PowerUp = GetWorld()->SpawnActor<AActor>(PowerUpClass, PowerUpLocation, FRotator::ZeroRotator);
 
        if (PowerUp)
        {
            UE_LOG(LogTemp, Warning, TEXT("Power-Up Spawned at: %s"), *PowerUpLocation.ToString());
        }
    }
}
