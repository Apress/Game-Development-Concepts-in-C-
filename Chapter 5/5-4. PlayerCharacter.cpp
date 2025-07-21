#include "PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

APlayerCharacter::APlayerCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
    JumpHeight = 600.0f;
    bIsGrounded = true;
}

void APlayerCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void APlayerCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Check if the player is grounded
    CheckGroundStatus();
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Bind the jump action
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::PerformJump);
}

 void APlayerCharacter::PerformJump()
{
    if (!GetCharacterMovement()->IsFalling())
    {
        LaunchCharacter(FVector(0, 0, JumpHeight), false, true);
    }
}


void APlayerCharacter::CheckGroundStatus()
{
    // Simple ground check logic
    if (GetCharacterMovement()->IsMovingOnGround())
    {
        bIsGrounded = true;
    }
}
