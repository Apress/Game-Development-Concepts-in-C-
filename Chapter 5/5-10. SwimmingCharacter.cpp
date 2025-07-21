#include "SwimmingCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TimerManager.h"
 
ASwimmingCharacter::ASwimmingCharacter()
{
    SwimSpeed = 300.0f;
    MaxBreathTime = 15.0f;
    BreathRemaining = MaxBreathTime;
    bIsSwimming = false;
}
 
void ASwimmingCharacter::BeginPlay()
{
    Super::BeginPlay();
}
 
void ASwimmingCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
 
    if (bIsSwimming)
    {
        GetCharacterMovement()->MaxWalkSpeed = SwimSpeed;
    }
}
 
void ASwimmingCharacter::StartSwimming()
{
    bIsSwimming = true;
    GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Flying);
 
    // Start breath timer
    GetWorldTimerManager().SetTimer(BreathTimerHandle, this, &ASwimmingCharacter::DecreaseBreath, 0.5f, true);
}
 
void ASwimmingCharacter::StopSwimming()
{
    bIsSwimming = false;
    GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking);
    BreathRemaining = MaxBreathTime;
 
    // Stop breath timer
    GetWorldTimerManager().ClearTimer(BreathTimerHandle);
}
 
void ASwimmingCharacter::DecreaseBreath()
{
    if (bIsSwimming && BreathRemaining > 0.0f)
    {
        BreathRemaining = FMath::Max(BreathRemaining - 1.0f, 0.0f);
 
        if (BreathRemaining <= 0.0f)
        {
            // Handle breath depletion logic here (e.g., apply damage)
        }
    }
}
