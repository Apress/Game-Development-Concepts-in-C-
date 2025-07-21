#pragma once

class UStaticMeshComponent;
class USphereComponent;

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotationObject.generated.h"

UCLASS()
class MYGAME_API ARotationObject : public AActor
{
    GENERATED_BODY()

public:    
    ARotationObject();

    UFUNCTION()
    void OnObjectCollision(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                           FVector NormalImpulse, const FHitResult& Hit);

private:
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* ObjectMesh;

    UPROPERTY(VisibleAnywhere)
    USphereComponent* CollisionSphere;

    UPROPERTY(EditDefaultsOnly, Category = "Rotation")
    float MaxRotationAngle;

    UPROPERTY(EditDefaultsOnly, Category = "Rotation")
    float CollisionThreshold;

    bool bIsRotationEnabled;

    void RotateObject(float ImpulseMagnitude);
};
