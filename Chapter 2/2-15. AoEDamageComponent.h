#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AoEDamageComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYGAME_API UAoEDamageComponent : public UActorComponent
{
    GENERATED_BODY()

public:    
    UAoEDamageComponent();

    UPROPERTY(EditAnywhere, Category = "AoE Damage")
    float AoERadius;

    UPROPERTY(EditAnywhere, Category = "AoE Damage")
    float DamageAmount;

protected:
    virtual void BeginPlay() override;

public:    
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    UFUNCTION()
    void ApplyAoEDamage();
};
