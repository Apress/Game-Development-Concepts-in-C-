#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AdvancedScriptingManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDamageTaken, float, DamageAmount);

UCLASS()
class MYGAME_API AAdvancedScriptingManager : public AActor
{
    GENERATED_BODY()

public:
    AAdvancedScriptingManager();

    UPROPERTY(BlueprintAssignable, Category = "Damage")
    FOnDamageTaken OnDamageTaken;

    UFUNCTION(BlueprintCallable, Category = "Damage")
    void ApplyDamage(float Damage);
};
