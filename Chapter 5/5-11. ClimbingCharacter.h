#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ClimbingCharacter.generated.h"

UCLASS()
class MYGAME_API AClimbingCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AClimbingCharacter();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Climbing")
    float ClimbSpeed; // Sets climbing speed

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Climbing")
    bool bCanClimb; // Detects if a surface is climbable

    UFUNCTION(BlueprintCallable, Category = "Climbing")
    void StartClimbing();

    UFUNCTION(BlueprintCallable, Category = "Climbing")
    void StopClimbing();

private:
    bool bIsClimbing; // Determines if the character is currently climbing
};
