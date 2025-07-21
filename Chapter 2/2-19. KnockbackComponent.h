#pragma once

#include "CoreMinimal.h"

class AActor;
class UCapsuleComponent;

#include "KnockbackComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYGAME_API UKnockbackComponent : public UActorComponent
{
    GENERATED_BODY()

public:    
    UKnockbackComponent();

    UPROPERTY(EditAnywhere, Category = "Knockback")
    float KnockbackForce;

    UPROPERTY(EditAnywhere, Category = "Knockback")
    float StunDuration;

protected:
    virtual void BeginPlay() override;

public:    
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    UFUNCTION()
    void ApplyKnockback(FVector KnockbackDirection);
};
