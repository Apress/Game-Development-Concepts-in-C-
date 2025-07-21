#pragma once

#include "CoreMinimal.h"

class AActor;
class UCapsuleComponent;

#include "DynamicPushbackComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYGAME_API UDynamicPushbackComponent : public UActorComponent
{
    GENERATED_BODY()

public:    
    UDynamicPushbackComponent();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    UFUNCTION()
    void ApplyDynamicPushback(FVector PushbackDirection, float Intensity);
};
