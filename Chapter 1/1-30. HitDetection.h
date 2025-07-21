#pragma once

class USphereComponent;

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HitDetection.generated.h"

UCLASS()
class MYGAME_API AHitDetection : public AActor
{
    GENERATED_BODY()

public:
    AHitDetection();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(VisibleAnywhere)
    USphereComponent* HitSphere;

    UFUNCTION()
    void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
};
