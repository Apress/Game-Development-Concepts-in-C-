#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"


class UBoxComponet;
class UPrimitiveComponent;

#include "Door.generated.h"

UCLASS()
class MYGAME_API ADoor : public AActor
{
    GENERATED_BODY()
    
public:    
    ADoor();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(VisibleAnywhere)
    UBoxComponent* TriggerBox;

    UPROPERTY(EditAnywhere)
    bool bIsLocked;

    UFUNCTION()
    void OnBeginOverlap (UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
