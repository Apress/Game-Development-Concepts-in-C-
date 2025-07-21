#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "StealthCharacter.generated.h"

UCLASS()
class MYGAME_API AStealthCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AStealthCharacter();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stealth")
    float StealthSoundRadius; // Sets the radius for sound detection

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stealth")
    float LineOfSightRange; // Sets the range of enemy vision

    UFUNCTION(BlueprintCallable, Category = "Stealth")
    void CheckForEnemies();

    UFUNCTION(BlueprintCallable, Category = "Stealth")
    void EnterStealthMode();

    UFUNCTION(BlueprintCallable, Category = "Stealth")
    void ExitStealthMode();

private:
    bool bIsStealthy; // Determines if the character is in stealth mode
};
