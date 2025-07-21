#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
class UsoundCue;
class UAudioComponent;
#include "EnvironmentalAmbienceManager.generated.h"

UCLASS()
class MYGAME_API AEnvironmentalAmbienceManager : public AActor
{
    GENERATED_BODY()

public:
    AEnvironmentalAmbienceManager();

    UFUNCTION(BlueprintCallable, Category = "Ambience")
    void PlayAmbience(USoundCue* AmbienceCue);

    UFUNCTION(BlueprintCallable, Category = "Ambience")
    void StopAmbience();

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(EditAnywhere, Category = "Ambience")
    USoundCue* DefaultAmbience ;

    UPROPERTY()
    UAudioComponent* ActiveAudioComponent ;
};
