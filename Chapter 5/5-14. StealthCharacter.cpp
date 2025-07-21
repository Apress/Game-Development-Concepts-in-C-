#include "StealthCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"

AStealthCharacter::AStealthCharacter()
{
    StealthSoundRadius = 300.0f;
    LineOfSightRange = 1000.0f;
    bIsStealthy = false;
}

void AStealthCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bIsStealthy)
    {
        CheckForEnemies();
    }
}

void AStealthCharacter::CheckForEnemies()
{
    // Implement logic to check for enemies within LineOfSightRange
    // and determine if the player is detected based on visibility and sound
}

void AStealthCharacter::EnterStealthMode()
{
    bIsStealthy = true;
    // Adjust movement or visibility attributes for stealth
}

void AStealthCharacter::ExitStealthMode()
{
    bIsStealthy = false;
    // Revert movement or visibility attributes to normal
}
