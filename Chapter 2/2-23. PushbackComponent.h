#pragma once

#include "CoreMinimal.h"

class AActor;
class UCapsuleComponent;

#include "PushbackComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYGAME_API UPushbackComponent : public UActorComponent
{
    GENERATED_BODY()

public:    
    UPushbackComponent();

    UPROPERTY(EditAnywhere, Category = "Pushback")
    float PushbackForce;

protected:
    virtual void BeginPlay() override;

public:    
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    UFUNCTION()
    void ApplyPushback(FVector PushbackDirection);
};
