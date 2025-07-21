#pragma once

class UStaticMeshComponent;
class USphereComponent;

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScalingObject.generated.h"

UCLASS()
class MYGAME_API AScalingObject : public AActor
{
    GENERATED_BODY()

public:    
    AScalingObject();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;

    UFUNCTION()
    void OnObjectCollision(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

private:
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* ObjectMesh;

    UPROPERTY(VisibleAnywhere)
    USphereComponent* CollisionSphere;

    UPROPERTY(EditDefaultsOnly, Category = "Scaling")
    float MinScale;

    UPROPERTY(EditDefaultsOnly, Category = "Scaling")
    float MaxScale;

    UPROPERTY(EditDefaultsOnly, Category = "Scaling")
    float CollisionThreshold;

    bool bIsScalingEnabled;

    void ScaleObject(float ImpulseMagnitude);
};
