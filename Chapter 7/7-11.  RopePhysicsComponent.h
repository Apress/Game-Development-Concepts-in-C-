#pragma once
 
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RopePhysicsComponent.generated.h"
 
USTRUCT(BlueprintType)
struct FNode
{
    GENERATED_BODY()
 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rope")
    FVector Position;
 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rope")
    FVector Velocity;
};
 
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MYGAME_API URopePhysicsComponent : public UActorComponent
{
    GENERATED_BODY()
 
public:
    URopePhysicsComponent();
 
protected:
    virtual void BeginPlay() override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
 
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rope")
    int32 NumNodes;
 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rope")
    float NodeMass;
 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rope")
    float SpringStiffness;
 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rope")
    TArray<FNode> RopeNodes;
 
    void SimulateRope(float DeltaTime);
    void ApplyForces(float DeltaTime);
    void EnforceConstraints();
};
