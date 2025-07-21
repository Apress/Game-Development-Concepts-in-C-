#include "CharacterMovementController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/InputComponent.h"

ACharacterMovementController::ACharacterMovementController()
{
    PrimaryActorTick.bCanEverTick = true;
    WalkSpeed = 300.0f;
    SprintSpeed = 600.0f;
}

void ACharacterMovementController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &ACharacterMovementController::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ACharacterMovementController::MoveRight);
    PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ACharacterMovementController::StartSprinting);
    PlayerInputComponent->BindAction("Sprint", IE_Released, this, &ACharacterMovementController::StopSprinting);
}

void ACharacterMovementController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ACharacterMovementController::MoveForward(float Value)
{
    if ((Controller != nullptr) && (Value != 0.0f))
    {
        const FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetUnitAxis(EAxis::X);
        AddMovementInput(Direction, Value);
    }
}

void ACharacterMovementController::MoveRight(float Value)
{
    if ((Controller != nullptr) && (Value != 0.0f))
    {
        const FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetUnitAxis(EAxis::Y);
        AddMovementInput(Direction, Value);
    }
}

void ACharacterMovementController::StartSprinting()
{
    GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
}

void ACharacterMovementController::StopSprinting()
{
    GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}
