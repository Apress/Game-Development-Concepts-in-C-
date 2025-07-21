#include "MeleeCombatController.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

AMeleeCombatController::AMeleeCombatController()
{
    PrimaryActorTick.bCanEverTick = true;
    MaxStamina = 100.0f;
    StaminaRegenRate = 5.0f;
    CurrentStamina = MaxStamina;
}

 void AMeleeCombatController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
 
    if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        EnhancedInput->BindAction(LightAttackAction, ETriggerEvent::Started, this, &AMeleeCombatController::LightAttack);
        EnhancedInput->BindAction(HeavyAttackAction, ETriggerEvent::Started, this, &AMeleeCombatController::HeavyAttack);
        EnhancedInput->BindAction(BlockAction, ETriggerEvent::Started, this, &AMeleeCombatController::Block);
    }
}

void AMeleeCombatController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Regenerate stamina over time
    RegenerateStamina(DeltaTime);
}

void AMeleeCombatController::LightAttack()
{
    if (CurrentStamina >= 10.0f)
    {
        // Execute light attack logic here
        CurrentStamina -= 10.0f;  // Deduct stamina for light attack
    }
}

void AMeleeCombatController::HeavyAttack()
{
    if (CurrentStamina >= 20.0f)
    {
        // Execute heavy attack logic here
        CurrentStamina -= 20.0f;  // Deduct stamina for heavy attack
    }
}

void AMeleeCombatController::Block()
{
    // Execute block logic here
}

void AMeleeCombatController::RegenerateStamina(float DeltaTime)
{
    if (CurrentStamina < MaxStamina)
    {
        CurrentStamina += StaminaRegenRate * DeltaTime;
        if (CurrentStamina > MaxStamina)
        {
            CurrentStamina = MaxStamina;
        }
    }
}
