#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class MYGAME_API AProjectile : public AActor
{
    GENERATED_BODY()
    
public:    
    AProjectile();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* ProjectileMesh;

    UPROPERTY(VisibleAnywhere)
    class UProjectileMovementComponent* ProjectileMovement;

    UFUNCTION()
    void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
};
