#pragma once

class ATriggerVolume

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TriggerVolume.generated.h"

UCLASS()
class MYGAME_API ATriggerVolume : public AActor
{
    GENERATED_BODY()

public:
    ATriggerVolume();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(VisibleAnywhere)
    UBoxComponent* TriggerBox;

    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
