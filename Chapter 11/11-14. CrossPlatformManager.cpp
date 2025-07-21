#include "CrossPlatformManager.h"
#include "Engine/Engine.h"
#include "GameFramework/InputSettings.h"

ACrossPlatformManager::ACrossPlatformManager()
{
    PrimaryActorTick.bCanEverTick = false;
}

 void ACrossPlatformManager::DetectPlatform()
{
#if PLATFORM_WINDOWS
    UE_LOG(LogTemp, Warning, TEXT("Running on Windows"));
#elif PLATFORM_ANDROID
    UE_LOG(LogTemp, Warning, TEXT("Running on Android"));
#elif PLATFORM_PS5
    UE_LOG(LogTemp, Warning, TEXT("Running on PlayStation 5"));
#else
    UE_LOG(LogTemp, Warning, TEXT("Running on an Unknown or Unsupported Platform"));
#endif
}

void ACrossPlatformManager::ConfigureInputSettings()
{
    UInputSettings* InputSettings = UInputSettings::GetInputSettings();
    if (InputSettings)
    {
        InputSettings->AddAxisMapping(FInputAxisKeyMapping("MoveForward", EKeys::W, 1.0f));
        InputSettings->AddAxisMapping(FInputAxisKeyMapping("MoveForward", EKeys::Gamepad_LeftStick_Up, 1.0f));
        InputSettings->SaveKeyMappings();
        UE_LOG(LogTemp, Warning, TEXT("Input settings configured for cross-platform use."));
    }
}
