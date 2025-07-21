#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ProceduralRotation.generated.h"

UCLASS()
class MYGAME_API UProceduralRotation : public UObject
{
    GENERATED_BODY()

public:
    UProceduralRotation();

    UFUNCTION(BlueprintCallable)
    void AdjustObjectRotation(float CollisionIntensity, float Velocity);

private:
    UPROPERTY(EditDefaultsOnly, Category = "Rotation")
    float MaxRotationAngle;

    UPROPERTY(EditDefaultsOnly, Category = "Rotation")
    float CollisionImpactThreshold;

    UPROPERTY(EditDefaultsOnly, Category = "Rotation")
    float MaxVelocityFactor;
};
