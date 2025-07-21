#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

class UBoxComponent;

#include "Trap.generated.h"

UCLASS()
class MYGAME_API ATrap : public AActor
{
    GENERATED_BODY()
    
public:    
    ATrap();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(VisibleAnywhere)
    UBoxComponent* TriggerBox;

    UFUNCTION()
    void OnOverlapBegin(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
};
