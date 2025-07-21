#include "DynamicLightManager.h"
#include "Engine/DirectionalLight.h"
#include "Kismet/GameplayStatics.h"

// Constructor: Sets default values
ADynamicLightManager::ADynamicLightManager()
{
    PrimaryActorTick.bCanEverTick = true;
    DayLength = 120.0f; // Default 2 minutes for day cycle
    NightLength = 60.0f; // Default 1 minute for night cycle
    CurrentTime = 0.0f;
    bIsDay = true;
}

// BeginPlay: Called when the game starts
void ADynamicLightManager::BeginPlay()
{
    Super::BeginPlay();
    TransitionToDay();
}

// Tick: Called every frame
void ADynamicLightManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    UpdateLighting(DeltaTime);
}

// SetDayLength: Update the length of the day cycle
void ADynamicLightManager::SetDayLength(float NewDayLength)
{
    DayLength = NewDayLength;
}

// SetNightLength: Update the length of the night cycle
void ADynamicLightManager::SetNightLength(float NewNightLength)
{
    NightLength = NewNightLength;
}

// UpdateLighting: Update the lighting based on current time
void ADynamicLightManager::UpdateLighting(float DeltaTime)
{
     CurrentTime += DeltaTime;
float TotalDayTime = DayLength + NightLength;
CurrentTime = FMath::Fmod(CurrentTime, TotalDayTime);

float NormalizedTime = CurrentTime / TotalDayTime; // Ranges from 0 to 1 across full cycle

// Cosine wave to simulate sunrise → midday → sunset
float LightIntensity = 0.0f;

if (CurrentTime < DayLength)
{
    if (!bIsDay)
    {
        TransitionToDay();
    }

    // Day curve: peak at midday
    float DayProgress = CurrentTime / DayLength; // 0 at sunrise, 1 at sunset
    LightIntensity = FMath::Clamp(FMath::Cos((DayProgress - 0.5f) * PI) * 5.0f, 0.0f, 5.0f); // Max intensity = 5
}
else
{
    if (bIsDay)
    {
        TransitionToNight();
    }

    // Night intensity stays low
    LightIntensity = 0.2f; // Example base intensity for moonlight or ambient night light
}

UDirectionalLight* DirectionalLight = GetDirectionalLight();
if (DirectionalLight)
{
    DirectionalLight->SetIntensity(LightIntensity);
}

}

// TransitionToDay: Handle the transition to daytime lighting
void ADynamicLightManager::TransitionToDay()
{
    bIsDay = true;
    // Additional logic for daytime transition (e.g., adjusting skybox)
}

// TransitionToNight: Handle the transition to nighttime lighting
void ADynamicLightManager::TransitionToNight()
{
    bIsDay = false;
    // Additional logic for nighttime transition (e.g., adjusting skybox)
}

// Helper function: Get the directional light in the scene
UDirectionalLight* ADynamicLightManager::GetDirectionalLight()
{
    TArray<AActor*> Lights;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADirectionalLight::StaticClass(), Lights);
    
    if (Lights.Num() > 0)
    {
        return Cast<UDirectionalLight>(Lights[0]);
    }

    return nullptr;
}
