#pragma once
 
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealthStaminaManager.generated.h"
 
UCLASS()
class MYGAME_API AHealthStaminaManager : public AActor
{
    GENERATED_BODY()
 
public:
    AHealthStaminaManager();
 
protected:
    virtual void BeginPlay() override;
 
public:
    virtual void Tick(float DeltaTime) override;
 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
    float MaxHealth;
 
    UPROPERTY(BlueprintReadOnly, Category = "Health")
    float CurrentHealth;
 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stamina")
    float MaxStamina;
 
    UPROPERTY(BlueprintReadOnly, Category = "Stamina")
    float CurrentStamina;
 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Regeneration")
    float StaminaRegenRate;
 
    UFUNCTION(BlueprintCallable, Category = "Health")
    void ApplyDamage(float DamageAmount);
 
    UFUNCTION(BlueprintCallable, Category = "Stamina")
    void ConsumeStamina(float StaminaCost);
 
private:
    // Timer-based stamina regen
    FTimerHandle StaminaRecoverTimer;
 
    UFUNCTION()
    void StaminaRecovery(); // Called periodically by the timer
};
