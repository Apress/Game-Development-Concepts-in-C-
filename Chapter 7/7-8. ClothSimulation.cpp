#include "ClothSimulation.h"
#include "Engine/World.h"

AClothSimulation::AClothSimulation()
{
    PrimaryActorTick.bCanEverTick = true;
    GravityStrength = 9.8f;
}

void AClothSimulation::BeginPlay()
{
    Super::BeginPlay();
}

void AClothSimulation::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Update cloth simulation each frame
    UpdateCloth(DeltaTime);
}

void AClothSimulation::UpdateCloth(float DeltaTime)
{
    for (int32 i = 0; i < ClothVertices.Num(); i++)
    {
        // Apply gravity force to each vertex
        ClothVertices[i] += FVector(0, 0, -GravityStrength) * DeltaTime;
        
        // Add additional forces (wind, collision, etc.) here
    }
}
