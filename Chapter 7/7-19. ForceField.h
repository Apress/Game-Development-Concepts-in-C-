#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ForceField.generated.h"

UCLASS()
class MYGAME_API AForceField : public AActor
{
    GENERATED_BODY()

public:
    AForceField();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Force Field")
    float ForceStrength;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Force Field")
    float FieldRadius;

    UFUNCTION(BlueprintCallable, Category = "Force Field")
    void SetForceStrength(float NewStrength);

    UFUNCTION(BlueprintCallable, Category = "Force Field")
    void SetFieldRadius(float NewRadius);

private:
    void ApplyForceToObjects();
};
