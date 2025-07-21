#include "WeatherManager.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Components/DirectionalLightComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Engine/DirectionalLight.h"
 
// Constructor: Sets default values
AWeatherManager::AWeatherManager()
{
    PrimaryActorTick.bCanEverTick = true;
}
 
// BeginPlay: Called when the game starts
void AWeatherManager::BeginPlay()
{
    Super::BeginPlay();
 
    // Initialize with a default weather state
    SetWeatherState(EWeatherState::Sunny);
}
 
// Tick: Called every frame
void AWeatherManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
 
    // Optional: Add logic to dynamically change weather over time
}
 
// SetWeatherState: Change the current weather state and update effects
void AWeatherManager::SetWeatherState(EWeatherState NewWeatherState)
{
    CurrentWeatherState = NewWeatherState;
    UpdateWeatherEffects();
}
 
// UpdateWeatherEffects: Apply the relevant changes based on the current weather state
void AWeatherManager::UpdateWeatherEffects()
{
    switch (CurrentWeatherState)
    {
        case EWeatherState::Sunny:
            ChangeWeatherToSunny();
            break;
 
        case EWeatherState::Rainy:
            ChangeWeatherToRainy();
            break;
 
        case EWeatherState::Foggy:
            ChangeWeatherToFoggy();
            break;
 
        case EWeatherState::Stormy:
            ChangeWeatherToStormy();
            break;
    }
}
 
// Refactored base function to apply weather settings
void AWeatherManager::ApplyWeatherSettings(float LightIntensity, bool bEnableRain, bool bEnableFog)
{
    UDirectionalLightComponent* DirectionalLight = GetDirectionalLight();
    if (DirectionalLight)
    {
        DirectionalLight->SetIntensity(LightIntensity);
    }
 
    ToggleRain(bEnableRain);
    ToggleFog(bEnableFog);
}
 
// ChangeWeatherToSunny: Set environment to sunny conditions
void AWeatherManager::ChangeWeatherToSunny()
{
    ApplyWeatherSettings(3.0f, false, false);
}
 
// ChangeWeatherToRainy: Set environment to rainy conditions
void AWeatherManager::ChangeWeatherToRainy()
{
    ApplyWeatherSettings(1.5f, true, false);
}
 
// ChangeWeatherToFoggy: Set environment to foggy conditions
void AWeatherManager::ChangeWeatherToFoggy()
{
    ApplyWeatherSettings(1.0f, false, true);
}
 
// ChangeWeatherToStormy: Set environment to stormy conditions
void AWeatherManager::ChangeWeatherToStormy()
{
    ApplyWeatherSettings(0.5f, true, false);
}
 
// GetDirectionalLight: Helper function to find the first directional light in the scene
UDirectionalLightComponent* AWeatherManager::GetDirectionalLight()
{
    TArray<AActor*> Lights;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADirectionalLight::StaticClass(), Lights);
 
    if (Lights.Num() > 0)
    {
        return Cast<ADirectionalLight>(Lights[0])->GetLightComponent();
    }
 
    return nullptr;
}
 
// ToggleRain: Placeholder for enabling/disabling rain particle systems
void AWeatherManager::ToggleRain(bool bEnable)
{
    // TODO: Implement logic to activate/deactivate rain particle systems
}
 
// ToggleFog: Placeholder for enabling/disabling fog particle systems
void AWeatherManager::ToggleFog(bool bEnable)
{
    // TODO: Implement logic to activate/deactivate fog particle systems
}
