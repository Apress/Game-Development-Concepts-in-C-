#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PuzzleInteraction.generated.h"

UCLASS()
class MYGAME_API APuzzleInteraction : public AActor
{
    GENERATED_BODY()
    
public:    
    APuzzleInteraction();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;

    UFUNCTION()
    void CheckPuzzleCondition();

private:
    TArray<APuzzleElement*> PuzzleElements;
    bool bIsPuzzleSolved;
};
