#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CharacterCustomizationManager.generated.h"

UCLASS()
class MYGAME_API ACharacterCustomizationManager : public AActor
{
    GENERATED_BODY()

public:
    ACharacterCustomizationManager();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Appearance")
    class USkeletalMeshComponent* CharacterMesh; // Character's mesh

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Appearance")
    TArray<class UMaterialInterface*> AvailableSkinTones; // Available skin tones for the character

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipment")
    class AWeapon* SelectedWeapon; // Selected weapon by the player

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int32 Strength; // Strength stat for character

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int32 Agility; // Agility stat for character

    UFUNCTION(BlueprintCallable, Category = "Customization")
    void ApplyAppearanceChanges(int32 SkinToneIndex);

    UFUNCTION(BlueprintCallable, Category = "Customization")
    void ApplyWeaponSelection(AWeapon* Weapon);
};
