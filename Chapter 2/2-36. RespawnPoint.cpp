#include "RespawnPoint.h"
#include "Components/BoxComponent.h"
#include "PlayerCharacter.h"
#include "Components/BoxComponent.h"

ARespawnPoint::ARespawnPoint()
{
    PrimaryActorTick.bCanEverTick = true;

    RespawnZone = CreateDefaultSubobject<UBoxComponent>(TEXT("RespawnZone"));
    RootComponent = RespawnZone;

    bIsActive = true;
}

void ARespawnPoint::BeginPlay()
{
    Super::BeginPlay();
    RespawnZone->OnComponentBeginOverlap.AddDynamic(this, &ARespawnPoint::RespawnPlayer);
}

void ARespawnPoint::RespawnPlayer(APlayerCharacter* Player)
{
    if (bIsActive)
    {
        FVector SpawnLocation = GetRandomRespawnLocation();
        Player->RespawnAtLocation(SpawnLocation);
        bIsActive = false; // Prevent multiple respawns at the same point simultaneously
    }
}

FVector ARespawnPoint::GetRandomRespawnLocation()
{
    if (RespawnZone)
    {
        // Get the center location of the RespawnZone
        FVector ZoneCenter = RespawnZone->GetComponentLocation();

        // Define the radius within which the random point will be found
        float Radius = 500.0f;  // Adjust the radius as needed

        // Try to get a random reachable point within the radius of the RespawnZone
        FVector RandomPoint = UGameplayStatics::GetRandomReachablePointInRadius(GetWorld(), ZoneCenter, Radius);

        return RandomPoint;
    }
    
    // Return default location if RespawnZone is not valid
    return FVector::ZeroVector;
}
