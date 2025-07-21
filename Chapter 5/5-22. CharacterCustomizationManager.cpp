#include "CharacterCustomizationManager.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/World.h"
#include "Weapon.h"

// Constructor: Sets default values
ACharacterCustomizationManager::ACharacterCustomizationManager()
{
    PrimaryActorTick.bCanEverTick = true;
    Strength = 10;  // Default value
    Agility = 10;   // Default value
}

// BeginPlay: Called when the game starts
void ACharacterCustomizationManager::BeginPlay()
{
    Super::BeginPlay();
}

// Tick: Called every frame
void ACharacterCustomizationManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// ApplyAppearanceChanges: Changes the skin tone based on the player's selection
void ACharacterCustomizationManager::ApplyAppearanceChanges(int32 SkinToneIndex)
{
    if (AvailableSkinTones.IsValidIndex(SkinToneIndex))
    {
        CharacterMesh->SetMaterial(0, AvailableSkinTones[SkinToneIndex]);
    }
}

// ApplyWeaponSelection: Updates the selected weapon
void ACharacterCustomizationManager::ApplyWeaponSelection(AWeapon* Weapon)
{
    SelectedWeapon = Weapon;
}
