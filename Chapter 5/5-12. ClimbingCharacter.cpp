#include "ClimbingCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

AClimbingCharacter::AClimbingCharacter()
{
    ClimbSpeed = 200.0f;
    bIsClimbing = false;
    bCanClimb = false;
}

void AClimbingCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bIsClimbing)
    {
        GetCharacterMovement()->MaxWalkSpeed = ClimbSpeed;
        // Apply climbing movement controls here
    }
}

 void AClimbingCharacter::StartClimbing()
{
    if (bCanClimb)
    {
        bIsClimbing = true;
        GetCharacterMovement()->SetMovementMode(MOVE_Flying);
 
        // Optional: Zero out velocity to prevent unintended drifting
        GetCharacterMovement()->Velocity = FVector::ZeroVector;
 
        // Optionally limit movement input to vertical axis only
        // You can set a flag to ignore MoveRight/Forward in your input handlers
    }
}


void AClimbingCharacter::StopClimbing()
{
    bIsClimbing = false;
    GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking);
}
