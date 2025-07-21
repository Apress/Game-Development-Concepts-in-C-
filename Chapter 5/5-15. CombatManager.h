#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CombatManager.generated.h"

UCLASS()
class MYGAME_API ACombatManager : public AActor
{
    GENERATED_BODY()

public:
    ACombatManager();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float AttackDamage;  // Base damage dealt per attack

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float StaminaCost;  // Stamina consumed per action

    UFUNCTION(BlueprintCallable, Category = "Combat")
    void PerformAttack();

    UFUNCTION(BlueprintCallable, Category = "Combat")
    void BlockAttack();

    UFUNCTION(BlueprintCallable, Category = "Combat")
    void Dodge();
};
