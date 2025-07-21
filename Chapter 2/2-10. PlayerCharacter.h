#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

class UCapsuleComponent;

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

    void MoveForward(float Value);
    void MoveRight(float Value);
    void JumpAction();

private:
    UPROPERTY(VisibleAnywhere)
    UCapsuleComponent* PlayerCapsule;
};
