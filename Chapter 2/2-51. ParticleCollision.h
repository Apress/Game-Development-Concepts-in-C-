#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

class UBoxComponent;
class UParticleSystemComponent;
class UParticleSystem;
class UPrimitiveComponent;

#include "ParticleCollision.generated.h"

UCLASS()
class MYGAME_API AParticleCollision : public AActor
{
    GENERATED_BODY()

public:    
    AParticleCollision();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(VisibleAnywhere)
    UBoxComponent* CollisionBox;

    UPROPERTY(VisibleAnywhere)
    UParticleSystemComponent* ParticleSystem;

    UPROPERTY(EditDefaultsOnly, Category = "Particles")
    UParticleSystem* CollisionParticles;

    UFUNCTION()
    void OnObjectCollision(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
