#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AI_DecisionTree.generated.h"

UCLASS()
class MYGAME_API AAI_DecisionTree : public ACharacter
{
    GENERATED_BODY()

public:
    AAI_DecisionTree();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    void MakeDecision();

private:
    bool bPlayerInSight;
    bool bPlayerTooClose;
};
