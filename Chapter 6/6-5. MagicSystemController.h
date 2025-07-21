#pragma once
 
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MagicSystemController.generated.h"
 
UCLASS()
class MYGAME_API AMagicSystemController : public AActor
{
    GENERATED_BODY()
 
public:
    AMagicSystemController();
 
protected:
    virtual void BeginPlay() override;
 
public:
    virtual void Tick(float DeltaTime) override;
 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Magic")
    float MaxMana;  // Maximum mana for the player
 
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Magic")
    float CurrentMana;  // Current mana available
 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Magic")
    TArray<TSubclassOf<class ASpell>> SpellList;  // List of spells available for casting
 
    UFUNCTION(BlueprintCallable, Category = "Magic")
    void CastSpell(int32 SpellIndex);
 
    UFUNCTION(BlueprintCallable, Category = "Magic")
    void RegenerateMana(float Amount);
};
