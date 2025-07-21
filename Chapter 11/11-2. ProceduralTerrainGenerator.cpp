#include "ProceduralTerrainGenerator.h"
#include "Kismet/KismetMathLibrary.h"

AProceduralTerrainGenerator::AProceduralTerrainGenerator()
{
    PrimaryActorTick.bCanEverTick = false;
    Width = 10;
    Height = 10;
    TileSize = 100.0f;
    NoiseScale = 10.0f;
}

void AProceduralTerrainGenerator::BeginPlay()
{
    Super::BeginPlay();
    GenerateTerrain();
}

void AProceduralTerrainGenerator::GenerateTerrain()
{
    for (int32 X = 0; X < Width; ++X)
    {
        for (int32 Y = 0; Y < Height; ++Y)
        {
            float NoiseValue = UKismetMathLibrary::PerlinNoise2D(FVector2D(X, Y) * NoiseScale);
            FVector Location = FVector(X * TileSize, Y * TileSize, NoiseValue * 100.0f);
            SpawnTile(Location);
        }
    }
}

void AProceduralTerrainGenerator::SpawnTile(FVector Location)
{
    // Replace with spawning logic for modular terrain pieces
    UE_LOG(LogTemp, Warning, TEXT("Tile spawned at: %s"), *Location.ToString());
}
