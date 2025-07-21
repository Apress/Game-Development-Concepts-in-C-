#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DynamicLightManager.generated.h"

UCLASS()
class MYGAME_API ADynamicLightManager : public AActor
{
    GENERATED_BODY()

public:
    ADynamicLightManager();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lighting")
    float DayLength;  // Time for a full day cycle in seconds

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lighting")
    float NightLength; // Time for a full night cycle in seconds

    UFUNCTION(BlueprintCallable, Category = "Lighting")
    void SetDayLength(float NewDayLength);

    UFUNCTION(BlueprintCallable, Category = "Lighting")
    void SetNightLength(float NewNightLength);

private:
    void UpdateLighting(float DeltaTime);
    void TransitionToDay();
    void TransitionToNight();

    float CurrentTime; // Track the current time of day
    bool bIsDay; // Track whether it's currently day or night
};
