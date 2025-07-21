#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnvironmentalInteractionComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYGAME_API UEnvironmentalInteractionComponent : public UActorComponent
{
    GENERATED_BODY()

public:    
    UEnvironmentalInteractionComponent();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    UFUNCTION()
    void TriggerExplosion();
};
