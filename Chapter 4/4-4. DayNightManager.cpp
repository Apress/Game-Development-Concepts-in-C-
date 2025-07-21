#include "DayNightManager.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Components/DirectionalLightComponent.h"
 
// Constructor: Sets default values
ADayNightManager::ADayNightManager()
{
    PrimaryActorTick.bCanEverTick = true;
    CurrentTime = 1200; // Start at noon
    SecondsPerMinute = 1.0f;
    TimeAccumulator = 0.0f;
}
 
// Called when the game starts
void ADayNightManager::BeginPlay()
{
    Super::BeginPlay();
}
 
// Called every frame
void ADayNightManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
 
    // Accumulate real time
    TimeAccumulator += DeltaTime;
 
    if (TimeAccumulator >= SecondsPerMinute)
    {
        TimeAccumulator -= SecondsPerMinute;
        IncrementTime();
    }
 
    UpdateDayNightCycle();
}
 
// Converts CurrentTime (HHMM) to float (e.g., 9.5 = 9:30 AM)
float ADayNightManager::GetTimeAsFloat() const
{
    int32 Hours = CurrentTime / 100;
    int32 Minutes = CurrentTime % 100;
    return Hours + (Minutes / 60.0f);
}
 
// Increments the in-game time by one minute
void ADayNightManager::IncrementTime()
{
    int32 Minutes = CurrentTime % 100;
    int32 Hours = CurrentTime / 100;
 
    Minutes++;
 
    if (Minutes >= 60)
    {
        Minutes = 0;
        Hours++;
        if (Hours >= 24)
        {
            Hours = 0;
        }
    }
 
    CurrentTime = Hours * 100 + Minutes;
}
 
// Updates lighting and sun position each frame
void ADayNightManager::UpdateDayNightCycle()
{
    UpdateLighting();
    UpdateSunPosition();
}
 
// Adjust the light intensity based on time of day
void ADayNightManager::UpdateLighting()
{
    if (SunLight)
    {
        float TimeFloat = GetTimeAsFloat();
        float Intensity = FMath::Clamp(FMath::Cos((TimeFloat - 6.0f) / 12.0f * PI), 0.0f, 1.0f);
        SunLight->GetLightComponent()->SetIntensity(Intensity * 3.0f); // Light intensity ranges from 0 to 3
    }
}
 
// Rotate the sun to simulate day-night cycle
void ADayNightManager::UpdateSunPosition()
{
    if (SunLight)
    {
        float TimeFloat = GetTimeAsFloat();
        FRotator NewRotation = FRotator((TimeFloat / 24.0f) * 360.0f - 90.0f, 0.0f, 0.0f);
        SunLight->SetActorRotation(NewRotation);
    }
}
