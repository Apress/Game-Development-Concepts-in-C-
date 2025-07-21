#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AIPathfinding.generated.h"

UCLASS()
class MYGAME_API AAIPathfinding : public AActor
{
    GENERATED_BODY()

public:
    AAIPathfinding();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UFUNCTION(BlueprintCallable, Category = "Pathfinding")
    void FindPath(FVector Start, FVector End);

private:
    TArray<FVector> CalculatePath(FVector Start, FVector End);
    float Heuristic(FVector A, FVector B);
    TArray<FVector> SmoothPath(TArray<FVector> Path);

    TArray<FVector> Path;
};
