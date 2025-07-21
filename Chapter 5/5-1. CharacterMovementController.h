#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterMovementController.generated.h"

UCLASS()
class MYGAME_API ACharacterMovementController : public ACharacter
{
    GENERATED_BODY()

public:
    ACharacterMovementController();

protected:
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    float WalkSpeed;  // Character’s walking speed

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    float SprintSpeed;  // Character’s sprinting speed

    UFUNCTION(BlueprintCallable, Category = "Movement")
    void MoveForward(float Value);

    UFUNCTION(BlueprintCallable, Category = "Movement")
    void MoveRight(float Value);

    UFUNCTION(BlueprintCallable, Category = "Movement")
    void StartSprinting();

    UFUNCTION(BlueprintCallable, Category = "Movement")
    void StopSprinting();
};
