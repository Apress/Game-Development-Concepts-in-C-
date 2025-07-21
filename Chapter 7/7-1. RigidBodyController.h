#pragma once
 
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RigidBodyController.generated.h"
 
UCLASS()
class MYGAME_API ARigidBodyController : public AActor
{
    GENERATED_BODY()
 
public:
    ARigidBodyController();
 
protected:
    virtual void BeginPlay() override;
 
public:
    virtual void Tick(float DeltaTime) override;
 
    // Mesh with physics
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* MeshComponent;
 
    // Apply custom external force
    UFUNCTION(BlueprintCallable, Category = "Physics")
    void ApplyForce(const FVector& Force);
};
