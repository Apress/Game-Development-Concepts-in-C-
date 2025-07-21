#include "TerrainDeformer.h"
#include "Components/StaticMeshComponent.h"

ATerrainDeformer::ATerrainDeformer()
{
    PrimaryActorTick.bCanEverTick = true;

    TerrainMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TerrainMesh"));
    RootComponent = TerrainMesh;

    DigDepth = 100.0f;
    BuildHeight = 200.0f;
}

void ATerrainDeformer::BeginPlay()
{
    Super::BeginPlay();

    if (TerrainMesh) // Ensure TerrainMesh is valid before accessing it
    {
        TerrainMesh->SetMaterial(0, DeformationMaterial);
    }
}

void ATerrainDeformer::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ATerrainDeformer::DigTerrain(FVector DigLocation, float DigRadius)
{
    // Implement logic to dig terrain at DigLocation with specified radius and depth
    // Modify terrain geometry or material properties based on dig action
}

void ATerrainDeformer::BuildStructure(FVector BuildLocation, float StructureSize)
{
    // Implement logic to build a structure at BuildLocation with specified size and height
    // Modify terrain geometry or material properties to incorporate built structure
}
