#include "ARInteractionManager.h"
#include "ARSessionConfig.h"
#include "Engine/World.h"

AARInteractionManager::AARInteractionManager()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AARInteractionManager::BeginPlay()
{
    Super::BeginPlay();
    UARBlueprintLibrary::StartARSession(NewObject<UARSessionConfig>());
}

void AARInteractionManager::SpawnARObject(FVector Location)
{
    if (ARObjectClass)
    {
        GetWorld()->SpawnActor<AActor>(ARObjectClass, Location, FRotator::ZeroRotator);
        UE_LOG(LogTemp, Warning, TEXT("AR Object Spawned at Location: %s"), *Location.ToString());
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("AR Object Class not set."));
    }
}

void AARInteractionManager::DetectARPlanes()
{
    DetectedPlanes.Empty();
    TArray<UARPlaneGeometry*> AllPlanes = UARBlueprintLibrary::GetAllTrackedPlanes();

    for (UARPlaneGeometry* Plane : AllPlanes)
    {
        if (Plane->GetTrackingState() == EARTrackingState::Tracking)
        {
            DetectedPlanes.Add(Plane);
            UE_LOG(LogTemp, Warning, TEXT("AR Plane Detected: %s"), *Plane->GetName());
        }
    }
}
