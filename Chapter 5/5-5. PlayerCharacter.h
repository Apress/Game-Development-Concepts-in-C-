#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class MYGAME_API APlayerCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    APlayerCharacter();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crouch")
    float CrouchSpeed; // Speed while crouching

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crouch")
    float StandSpeed; // Speed while standing

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crouch")
    bool bIsCrouching; // Tracks crouching state

    UFUNCTION(BlueprintCallable, Category = "Crouch")
    void StartCrouch();

    UFUNCTION(BlueprintCallable, Category = "Crouch")
    void EndCrouch();

private:
    void AdjustCrouchState(bool bCrouch);
};
