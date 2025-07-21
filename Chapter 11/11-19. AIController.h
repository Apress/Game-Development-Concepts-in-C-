#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AdaptiveAIController.generated.h"

UCLASS()
class MYGAME_API AAdaptiveAIController : public AAIController
{
    GENERATED_BODY()

public:
    virtual void Tick(float DeltaTime) override;

protected:
    virtual void BeginPlay() override;

private:
    void AdjustBehaviorBasedOnPlayer();
};
