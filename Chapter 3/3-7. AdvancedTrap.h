#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

class UBoxComponent;

#include "AdvancedTrap.generated.h"

UCLASS()
class MYGAME_API AAdvancedTrap : public AActor
{
    GENERATED_BODY()
    
public:    
    AAdvancedTrap();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(VisibleAnywhere)
    UBoxComponent* TriggerBox;

    UPROPERTY(EditAnywhere)
    bool bIsArmed;

    UFUNCTION()
    void OnOverlapBegin(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

    void ActivateTrap();
    void ResetTrap();
};
