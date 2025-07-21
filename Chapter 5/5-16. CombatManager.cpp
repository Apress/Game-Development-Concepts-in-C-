#include "CombatManager.h"

// Constructor
ACombatManager::ACombatManager()
{
    PrimaryActorTick.bCanEverTick = true;
    AttackDamage = 25.0f;
    StaminaCost = 10.0f;
}

// BeginPlay: Initializes Combat Settings
void ACombatManager::BeginPlay()
{
    Super::BeginPlay();
}

// Tick: Updates per frame
void ACombatManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// PerformAttack: Executes attack and deals damage if successful
void ACombatManager::PerformAttack()
{
    if (CanAttack())
    {
        DealDamage(AttackDamage);
        ReduceStamina(StaminaCost);
        PlayAttackAnimation();
    }
}

// BlockAttack: Reduces damage while blocking
void ACombatManager::BlockAttack()
{
    if (CanBlock())
    {
        ActivateBlock();
        PlayBlockAnimation();
    }
}

// Dodge: Evades incoming attacks
void ACombatManager::Dodge()
{
    if (CanDodge())
    {
        Evade();
        ReduceStamina(StaminaCost / 2);
        PlayDodgeAnimation();
    }
}
