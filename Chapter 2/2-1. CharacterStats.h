#pragma once

#include "CoreMinimal.h"
#include "CharacterStats.generated.h"

USTRUCT(BlueprintType)
struct MYGAME_API FCharacterStats
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float Health;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float AttackPower;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float Defense;
};
