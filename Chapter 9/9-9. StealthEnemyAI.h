#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "StealthEnemyAI.generated.h"

UCLASS()
class MYGAME_API AStealthEnemyAI : public ACharacter
{
    GENERATED_BODY()

public:
    AStealthEnemyAI();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    void DetectPlayer();
    void SearchForPlayer();
    void ReturnToPatrol();

private:
    bool bPlayerDetected;
    FVector LastKnownPlayerLocation;
};
