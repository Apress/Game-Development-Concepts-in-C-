#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeatherManager.generated.h"

UCLASS()
class MYGAME_API AWeatherManager : public AActor
{
    GENERATED_BODY()

public:
    AWeatherManager();

    UFUNCTION(BlueprintCallable, Category = "Weather")
    void SetWeatherCondition(FString WeatherCondition);

    UFUNCTION(BlueprintCallable, Category = "Weather")
    void UpdateWeather(float DeltaTime);

private:
    FString CurrentWeather;
    float WeatherTransitionTime;
    float WeatherTransitionProgress;
};

