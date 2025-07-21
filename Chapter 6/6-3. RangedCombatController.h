#pragma once
 
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RangedCombatController.generated.h"
 
UCLASS()
class MYGAME_API ARangedCombatController : public ACharacter
{
    GENERATED_BODY()
 
public:
    ARangedCombatController();
 
protected:
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    virtual void BeginPlay() override;
 
public:
    virtual void Tick(float DeltaTime) override;
 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float FireRate;  // Rate of fire for ranged weapons
 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    int32 MaxAmmo;  // Maximum ammo for the weapon
 
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
    int32 CurrentAmmo;  // Current ammo available
 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float ReloadDuration;  // Time it takes to reload the weapon
 
    UFUNCTION(BlueprintCallable, Category = "Combat")
    void FireWeapon();
 
    UFUNCTION(BlueprintCallable, Category = "Combat")
    void ReloadWeapon();
 
private:
    FTimerHandle ReloadTimerHandle;
    void FinishReload();
 
    bool bIsReloading;
};
