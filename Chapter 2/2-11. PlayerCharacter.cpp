#include "PlayerCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PlayerController.h"

APlayerCharacter::APlayerCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    PlayerCapsule = GetCapsuleComponent();
    PlayerCapsule->InitCapsuleSize(42.f, 96.0f);

    GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
    GetCharacterMovement()->JumpZVelocity = 600.f;
}

void APlayerCharacter::BeginPlay()
{
    Super::BeginPlay();

    APlayerController* MyController = Cast<APlayerController>(GetController());
    if (MyController)
    {
        UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(MyController->GetLocalPlayer());
        if (Subsystem)
        {
            Subsystem->AddMappingContext(MappingContext, 0);
        }
    }
}

void APlayerCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void APlayerCharacter::MoveForward(const FInputActionValue& Value)
{
    if ((Controller != nullptr) && (Value.GetMagnitude() != 0.0f))
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
        AddMovementInput(Direction, Value.GetMagnitude());
    }
}

void APlayerCharacter::MoveRight(const FInputActionValue& Value)
{
    if ((Controller != nullptr) && (Value.GetMagnitude() != 0.0f))
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
        AddMovementInput(Direction, Value.GetMagnitude());
    }
}

void APlayerCharacter::JumpAction(const FInputActionValue& Value)
{
    if (CanJump())
    {
        bPressedJump = true;
    }
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    UEnhancedInputComponent* MyInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
    if (MyInputComponent)
    {
        MyInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerCharacter::MoveForward);
        MyInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APlayerCharacter::MoveRight);
        MyInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &APlayerCharacter::JumpAction);
    }
}
