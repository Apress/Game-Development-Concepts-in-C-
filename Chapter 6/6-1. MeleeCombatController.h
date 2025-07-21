#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputAction.h"
#include "MeleeCombatController.generated.h"

UCLASS()
class MYGAME_API AMeleeCombatController : public ACharacter
{
    GENERATED_BODY()

public:
    AMeleeCombatController();

protected:
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float MaxStamina;  // The maximum stamina available for the player

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float StaminaRegenRate;  // The rate at which stamina regenerates

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
    float CurrentStamina;  // The current stamina the player has available

    UFUNCTION(BlueprintCallable, Category = "Combat")
    void LightAttack();

    UFUNCTION(BlueprintCallable, Category = "Combat")
    void HeavyAttack();

    UFUNCTION(BlueprintCallable, Category = "Combat")
    void Block();

    UFUNCTION(BlueprintCallable, Category = "Combat")
    void RegenerateStamina(float DeltaTime);

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    class UInputAction* LightAttackAction;
 
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    class UInputAction* HeavyAttackAction;
 
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    class UInputAction* BlockAction;
};
