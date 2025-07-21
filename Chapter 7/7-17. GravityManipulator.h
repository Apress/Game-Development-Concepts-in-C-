#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GravityManipulator.generated.h"

UCLASS()
class MYGAME_API AGravityManipulator : public AActor
{
    GENERATED_BODY()

public:
    AGravityManipulator();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gravity")
    FVector GravityDirection;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gravity")
    float GravityStrength;

    UFUNCTION(BlueprintCallable, Category = "Gravity")
    void SetGravity(const FVector& NewDirection, float NewStrength);

private:
    void ApplyGravity();
};
