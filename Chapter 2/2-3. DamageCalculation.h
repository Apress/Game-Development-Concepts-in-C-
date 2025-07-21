#pragma once

#include "CoreMinimal.h"
#include "CharacterStats.h"
#include "DamageCalculation.generated.h"

UCLASS()
class MYGAME_API UDamageCalculation : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Combat")
    static float CalculateDamage(const FCharacterStats& AttackerStats, const FCharacterStats& TargetStats);

    UFUNCTION(BlueprintCallable, Category = "Combat")
    static void ApplyDamage(FCharacterStats& TargetStats, float Damage);
};
