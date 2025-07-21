#pragma once

#include "CoreMinimal.h"

class AActor;

#include "DirectionalInfluenceComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYGAME_API UDirectionalInfluenceComponent : public UActorComponent
{
    GENERATED_BODY()

public:    
    UDirectionalInfluenceComponent();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    UFUNCTION()
    void ApplyDirectionalInfluence(FVector Direction);
};
