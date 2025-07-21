#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TerrainPhysics.generated.h"

UCLASS()
class MYGAME_API UTerrainPhysics : public UObject
{
    GENERATED_BODY()

public:
    UTerrainPhysics();

    UFUNCTION(BlueprintCallable)
    void SimulateTerrainErosion(float ErosionStrength);

    UFUNCTION(BlueprintCallable)
    void ApplyPhysicsForces(FVector ImpactPoint, float ImpactForce);

private:
    UPROPERTY(EditDefaultsOnly, Category = "Physics")
    float TerrainStrength;

    UPROPERTY(EditDefaultsOnly, Category = "Physics")
    float ErosionRate;

    UPROPERTY(EditDefaultsOnly, Category = "Physics")
    float ImpactForceMultiplier;
};
