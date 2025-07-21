#pragma once

class UStaticMeshComponent;

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TerrainDeformer.generated.h"

UCLASS()
class MYGAME_API ATerrainDeformer : public AActor
{
    GENERATED_BODY()

public:    
    ATerrainDeformer();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;

    UFUNCTION(BlueprintCallable)
    void DigTerrain(FVector DigLocation, float DigRadius);

    UFUNCTION(BlueprintCallable)
    void BuildStructure(FVector BuildLocation, float StructureSize);

private:
    UPROPERTY(EditDefaultsOnly, Category = "Deformation")
    UStaticMeshComponent* TerrainMesh;

    UPROPERTY(EditDefaultsOnly, Category = "Deformation")
    UMaterialInterface* DeformationMaterial;

    UPROPERTY(EditDefaultsOnly, Category = "Deformation")
    float DigDepth;

    UPROPERTY(EditDefaultsOnly, Category = "Deformation")
    float BuildHeight;
};
