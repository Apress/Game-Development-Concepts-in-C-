#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ProceduralScaling.generated.h"

UCLASS()
class MYGAME_API UProceduralScaling : public UObject
{
    GENERATED_BODY()

public:
    UProceduralScaling();

    UFUNCTION(BlueprintCallable)
    void AdjustObjectScale(float CollisionIntensity, float Velocity);

private:
    UPROPERTY(EditDefaultsOnly, Category = "Scaling")
    float MinScaleFactor;

    UPROPERTY(EditDefaultsOnly, Category = "Scaling")
    float MaxScaleFactor;

    UPROPERTY(EditDefaultsOnly, Category = "Scaling")
    float CollisionImpactThreshold;

    UPROPERTY(EditDefaultsOnly, Category = "Scaling")
    float MaxVelocityFactor;
};
