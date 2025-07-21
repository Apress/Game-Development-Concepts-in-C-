#include "HealthStaminaManager.h"
#include "TimerManager.h"
 
AHealthStaminaManager::AHealthStaminaManager()
{
    PrimaryActorTick.bCanEverTick = true;
 
    MaxHealth = 100.0f;
    CurrentHealth = MaxHealth;
 
    MaxStamina = 100.0f;
    CurrentStamina = MaxStamina;
 
    StaminaRegenRate = 5.0f;
}
 
void AHealthStaminaManager::BeginPlay()
{
    Super::BeginPlay();
 
    // Start timer to recover stamina every 0.5 seconds
    GetWorldTimerManager().SetTimer(StaminaRecoverTimer, this, &AHealthStaminaManager::StaminaRecovery, 0.5f, true);
}
 
void AHealthStaminaManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
 
    // No stamina regen here anymore – handled by timer
}
 
void AHealthStaminaManager::ApplyDamage(float DamageAmount)
{
    CurrentHealth -= DamageAmount;
    if (CurrentHealth <= 0.0f)
    {
        CurrentHealth = 0.0f;
        // TODO: Trigger player death logic
    }
}
 
void AHealthStaminaManager::ConsumeStamina(float StaminaCost)
{
    if (CurrentStamina >= StaminaCost)
    {
        CurrentStamina -= StaminaCost;
    }
}
 
void AHealthStaminaManager::StaminaRecovery()
{
    if (CurrentStamina < MaxStamina)
    {
        CurrentStamina = FMath::Min(CurrentStamina + (StaminaRegenRate * 0.5f), MaxStamina);
    }
}
