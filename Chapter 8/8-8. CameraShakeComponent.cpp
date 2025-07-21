#include "CameraShakeComponent.h"
#include "GameFramework/PlayerController.h"
#include "Camera/PlayerCameraManager.h"
#include "Kismet/GameplayStatics.h"
 
UCameraShakeComponent::UCameraShakeComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    ShakeScale = 1.0f;
}
 
void UCameraShakeComponent::TriggerSprintShake()
{
    APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if (PC && SprintShake)
    {
        PC->PlayerCameraManager->StartCameraShake(SprintShake, ShakeScale);
    }
}
 
void UCameraShakeComponent::TriggerLandingShake()
{
    APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if (PC && LandingShake)
    {
        PC->PlayerCameraManager->StartCameraShake(LandingShake, ShakeScale);
    }
}
