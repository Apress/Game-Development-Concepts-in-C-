#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

class UBoxComponent;

#include "AdvancedDoor.generated.h"

UCLASS()
class MYGAME_API AAdvancedDoor : public AActor
{
    GENERATED_BODY()
    
public:    
    AAdvancedDoor();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(VisibleAnywhere)
    UBoxComponent* TriggerBox;

    UPROPERTY(EditAnywhere)
    bool bIsLocked;

    UPROPERTY(EditAnywhere)
    FString RequiredKey;

    UFUNCTION()
    void OnBeginOverlap (UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
};
