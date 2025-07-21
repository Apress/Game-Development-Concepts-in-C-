#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SoftBodyController.generated.h"

UCLASS()
class MYGAME_API ASoftBodyController : public AActor
{
    GENERATED_BODY()

public:
    ASoftBodyController();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Soft Body")
    float SpringConstant; // How stiff the soft body is

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Soft Body")
    float Damping; // Damping of the spring force

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Soft Body")
    TArray<FVector> Masses; // The points representing the soft body

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Soft Body")
    TArray<FVector> Velocities; // The velocities of each mass

    void ApplyForce(FVector Force, int32 MassIndex);
    void SimulateSoftBody(float DeltaTime);
};
