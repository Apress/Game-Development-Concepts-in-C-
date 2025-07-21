#pragma once

class UParticleSystemComponent;
class UParticleSystem;

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DynamicParticles.generated.h"

UCLASS()
class MYGAME_API UDynamicParticles : public UObject
{
    GENERATED_BODY()

public:
    UDynamicParticles();

    UFUNCTION(BlueprintCallable)
    void AdjustParticleEffects(float CollisionIntensity, FVector CollisionDirection);

private:
    UPROPERTY(EditDefaultsOnly, Category = "Particles")
    UParticleSystem* ImpactParticles;

    UPROPERTY(EditDefaultsOnly, Category = "Particles")
    float MaxEmissionRate;

    UPROPERTY(EditDefaultsOnly, Category = "Particles")
    FVector ParticleDirection;
};
