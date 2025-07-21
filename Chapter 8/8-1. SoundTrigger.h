#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

class USoundBase;
class UBoxComponent;

#include "SoundTrigger.generated.h"

UCLASS()
class MYGAME_API ASoundTrigger : public AActor
{
    GENERATED_BODY()

public:
    ASoundTrigger();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
    USoundBase* TriggerSound ;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
    float TriggerDistance;

    UFUNCTION(BlueprintCallable, Category = "Sound")
    void PlaySoundAtTrigger();

private:
    void CheckTriggerDistance();
};
