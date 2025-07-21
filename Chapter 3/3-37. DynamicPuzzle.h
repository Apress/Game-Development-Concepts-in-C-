#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

class UStaticMeshComponent;

#include "DynamicPuzzle.generated.h"

UCLASS()
class MYGAME_API ADynamicPuzzle : public AActor
{
    GENERATED_BODY()
    
public:    
    ADynamicPuzzle();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;

    UFUNCTION()
    void OnPlayerInteraction();

private:
    UPROPERTY(VisibleAnywhere)
    TArray<UStaticMeshComponent*> PuzzleMeshes;

    bool bIsPuzzleSolved;
};
