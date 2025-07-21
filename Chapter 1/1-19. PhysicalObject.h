#pragma once
class UStaticMeshComponent;

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PhysicalObject.generated.h"

UCLASS()
class MYGAME_API APhysicalObject : public AActor
{
    GENERATED_BODY()

public:
    APhysicalObject();

private:
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* ObjectMesh;

    UPROPERTY(VisibleAnywhere)
    UPhysicsConstraintComponent* PhysicsConstraint;
};
