#include "DamageCalculation.h"
#include "CharacterStats.h"

float UDamageCalculation::CalculateDamage(const FCharacterStats& AttackerStats, const FCharacterStats& TargetStats)
{
    // Base damage calculation
    float BaseDamage = AttackerStats.AttackPower - TargetStats.Defense;
    if (BaseDamage < 0)
    {
        BaseDamage = 0;
    }

    // Apply random variance (optional)
    float DamageVariance = FMath::RandRange(0.9f, 1.1f);
    float FinalDamage = BaseDamage * DamageVariance;

    return FinalDamage;
}

void UDamageCalculation::ApplyDamage(FCharacterStats& TargetStats, float Damage)
{
    TargetStats.Health -= Damage;
    if (TargetStats.Health < 0)
    {
        TargetStats.Health = 0;
    }
}
