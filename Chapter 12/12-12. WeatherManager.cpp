#include "WeatherManager.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

AWeatherManager::AWeatherManager()
{
    PrimaryActorTick.bCanEverTick = true;
    WeatherTransitionTime = 5.0f;  // Time to transition to the next weather condition (in seconds)
    WeatherTransitionProgress = 0.0f;
}

void AWeatherManager::SetWeatherCondition(FString WeatherCondition)
{
    CurrentWeather = WeatherCondition;
    WeatherTransitionProgress = 0.0f;  // Reset transition progress
    UE_LOG(LogTemp, Warning, TEXT("Weather set to: %s"), *WeatherCondition);
}

void AWeatherManager::UpdateWeather(float DeltaTime)
{
    if (WeatherTransitionProgress < WeatherTransitionTime)
    {
        WeatherTransitionProgress += DeltaTime;
        // Gradually update weather effects like light, fog, and particle systems here
        UE_LOG(LogTemp, Warning, TEXT("Transitioning weather: %f%%"), (WeatherTransitionProgress / WeatherTransitionTime) * 100);
    }
    else
    {
        // Apply the full weather effects for the current weather condition
        if (CurrentWeather == "Rainy")
        {
            // Example: Increase particle effects for rain
        }
        else if (CurrentWeather == "Sunny")
        {
            // Example: Clear sky, no rain
        }
        // Add more conditions for other weather types
    }
}

