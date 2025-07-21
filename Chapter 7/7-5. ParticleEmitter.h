#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ParticleEmitter.generated.h"

UCLASS()
class MYGAME_API AParticleEmitter : public AActor
{
    GENERATED_BODY()

public:
    AParticleEmitter();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")
    int32 MaxParticles;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")
    float ParticleLifetime;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")
    FVector ParticleVelocity;

    TArray<FVector> Particles;  // Array to store the particle positions
    TArray<float> Lifetimes;    // Array to store the lifetime of each particle

    void EmitParticle();
    void UpdateParticles(float DeltaTime);
};
