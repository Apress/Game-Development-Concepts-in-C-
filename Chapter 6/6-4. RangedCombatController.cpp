#include "RangedCombatController.h"
#include "Components/InputComponent.h"
#include "TimerManager.h"
 
ARangedCombatController::ARangedCombatController()
{
    PrimaryActorTick.bCanEverTick = true;
 
    FireRate = 0.5f;
    MaxAmmo = 30;
    CurrentAmmo = MaxAmmo;
    ReloadDuration = 2.0f;
    bIsReloading = false;
}
 
void ARangedCombatController::BeginPlay()
{
    Super::BeginPlay();
}
 
void ARangedCombatController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
 
void ARangedCombatController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
 
    PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ARangedCombatController::FireWeapon);
    PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &ARangedCombatController::ReloadWeapon);
}
 
void ARangedCombatController::FireWeapon()
{
    if (bIsReloading)
        return;
 
    if (CurrentAmmo > 0)
    {
        // Fire the weapon and subtract one from the ammo count
        CurrentAmmo--;
 
        // TODO: Add shooting logic (e.g., projectile spawn, sound, etc.)
    }
    else
    {
        // Ammo is depleted, trigger reload
        ReloadWeapon();
    }
}
 
void ARangedCombatController::ReloadWeapon()
{
    if (bIsReloading || CurrentAmmo == MaxAmmo)
        return;
 
    bIsReloading = true;
 
    // TODO: Play reload animation or sound here
 
    // Start reload timer
    GetWorldTimerManager().SetTimer(ReloadTimerHandle, this, &ARangedCombatController::FinishReload, ReloadDuration, false);
}
 
void ARangedCombatController::FinishReload()
{
    CurrentAmmo = MaxAmmo;
    bIsReloading = false;
 
    // TODO: Trigger reload complete feedback here (UI, sound, etc.)
}
