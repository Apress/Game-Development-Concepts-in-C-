#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralTerrainGenerator.generated.h"

UCLASS()
class MYGAME_API AProceduralTerrainGenerator : public AActor
{
    GENERATED_BODY()

public:
    AProceduralTerrainGenerator();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Terrain")
    int32 Width;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Terrain")
    int32 Height;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Terrain")
    float TileSize;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Terrain")
    float NoiseScale;

protected:
    virtual void BeginPlay() override;

    void GenerateTerrain();

private:
    void SpawnTile(FVector Location);
};
