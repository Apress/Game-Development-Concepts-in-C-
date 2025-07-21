#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NavigationSystem.h"
#include "PathfindingOptimization.generated.h"

UCLASS()
class MYGAME_API APathfindingOptimization : public AActor
{
    GENERATED_BODY()

public:
    APathfindingOptimization();

    UFUNCTION(BlueprintCallable, Category = "Pathfinding")
    void FindOptimizedPath(FVector StartLocation, FVector EndLocation);

protected:
    virtual void BeginPlay() override;

private:
    UNavigationSystemV1* NavSystem;
};
