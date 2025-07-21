#include "MagicSystemController.h"
#include "Spell.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
 
AMagicSystemController::AMagicSystemController()
{
    PrimaryActorTick.bCanEverTick = true;
 
    MaxMana = 100.0f;
    CurrentMana = MaxMana;
}
 
void AMagicSystemController::BeginPlay()
{
    Super::BeginPlay();
}
 
void AMagicSystemController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
 
void AMagicSystemController::CastSpell(int32 SpellIndex)
{
    if (CurrentMana <= 0 || !SpellList.IsValidIndex(SpellIndex))
        return;
 
    // Set spawn location/rotation (e.g., from player or controller location)
    FVector SpawnLocation = GetActorLocation() + GetActorForwardVector() * 100.f; // In front of player
    FRotator SpawnRotation = GetActorRotation();
 
    // Spawn the spell actor
    ASpell* SelectedSpell = GetWorld()->SpawnActor<ASpell>(
        SpellList[SpellIndex],
        SpawnLocation,
        SpawnRotation
    );
 
    if (SelectedSpell)
    {
        // Cast the spell and subtract mana
        SelectedSpell->CastSpell();
        CurrentMana = FMath::Clamp(CurrentMana - SelectedSpell->GetManaCost(), 0.0f, MaxMana);
    }
}
 
void AMagicSystemController::RegenerateMana(float Amount)
{
    CurrentMana = FMath::Clamp(CurrentMana + Amount, 0.0f, MaxMana);
}
