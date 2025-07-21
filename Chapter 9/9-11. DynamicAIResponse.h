#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DynamicAIResponse.generated.h"

class USphereComponent;

UCLASS()
class MYGAME_API ADynamicAIResponse : public ACharacter
{
    GENERATED_BODY()

public:
    ADynamicAIResponse();

protected:
    virtual void BeginPlay() override;

    // Detection overlap event
    UFUNCTION()
    void OnPlayerDetected(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                          UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
                          bool bFromSweep, const FHitResult& SweepResult);

public:
    void ReactToThreat();
    void ReturnToNormalState();

private:
    UPROPERTY(VisibleAnywhere, Category = "Detection")
    USphereComponent* DetectionSphere;

    bool bPlayerDetected;
    bool bIsUnderThreat;
    FVector LastKnownPlayerLocation;
};
