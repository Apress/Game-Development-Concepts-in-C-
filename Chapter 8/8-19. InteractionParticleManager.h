#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
class UParticleSystem;
#include "InteractionParticleManager.generated.h"

UCLASS()
class MYGAME_API AInteractionParticleManager : public AActor
{
    GENERATED_BODY()

public:
    AInteractionParticleManager();

    UFUNCTION(BlueprintCallable, Category = "Particles")
    void SpawnParticleEffect(FVector Location, UParticleSystem* ParticleEffect);

protected:
    virtual void BeginPlay() override;
};
