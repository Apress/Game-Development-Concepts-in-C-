#pragma once

class ATriggerVolume;

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoorTrigger.generated.h"

UCLASS()
class MYGAME_API ADoorTrigger : public AActor
{
    GENERATED_BODY()
    
public:    
    ADoorTrigger();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(VisibleAnywhere)
    ATriggerVolume* DoorTrigger;

    UFUNCTION()
    void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

    UFUNCTION()
    void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
};
