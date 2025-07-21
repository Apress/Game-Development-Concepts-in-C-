#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FluidSimulator.generated.h"

UCLASS()
class MYGAME_API AFluidSimulator : public AActor
{
    GENERATED_BODY()

public:
    AFluidSimulator();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fluid")
    int32 MaxParticles;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fluid")
    float ParticleRadius;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fluid")
    float Viscosity;

    UFUNCTION(BlueprintCallable, Category = "Fluid")
    void AddParticle(const FVector& Position, const FVector& Velocity);

private:
    TArray<FVector> ParticlePositions;
    TArray<FVector> ParticleVelocities;

    void UpdateParticles(float DeltaTime);
    void RenderParticles();
};
