#include "PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

APlayerCharacter::APlayerCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
    CrouchSpeed = 300.0f;
    StandSpeed = 600.0f;
    bIsCrouching = false;
}

void APlayerCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void APlayerCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &APlayerCharacter::StartCrouch);
    PlayerInputComponent->BindAction("Crouch", IE_Released, this, &APlayerCharacter::EndCrouch);
}

void APlayerCharacter::StartCrouch()
{
    AdjustCrouchState(true);
}

void APlayerCharacter::EndCrouch()
{
    AdjustCrouchState(false);
}

void APlayerCharacter::AdjustCrouchState(bool bCrouch)
{
    if (bCrouch)
    {
        Crouch();
        GetCharacterMovement()->MaxWalkSpeed = CrouchSpeed;
        bIsCrouching = true;
    }
    else
    {
        UnCrouch();
        GetCharacterMovement()->MaxWalkSpeed = StandSpeed;
        bIsCrouching = false;
    }
}
