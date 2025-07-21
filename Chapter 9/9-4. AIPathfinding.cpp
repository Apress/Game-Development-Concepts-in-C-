#include "AIPathfinding.h"
#include "NavigationSystem.h"
#include "NavigationPath.h"
#include "AIController.h"

#include "Kismet/GameplayStatics.h"

AAIPathfinding::AAIPathfinding()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AAIPathfinding::BeginPlay()
{
    Super::BeginPlay();
}

 void AAIPathfinding::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
 
    // Only find a new path if necessary
    if (bShouldFindPath)
    {
        FVector Start = GetActorLocation();
        FVector End = TargetLocation; // Set dynamically somewhere else in the game
        FindPath(Start, End);
        bShouldFindPath = false; // Reset until next update
    }
 
    // Continue movement logic if you already have a path
    FollowPath(DeltaTime);
}

void AAIPathfinding::FindPath(FVector Start, FVector End)
{
    Path = CalculatePath(Start, End);
    Path = SmoothPath(Path);
}

 TArray<FVector> AAIPathfinding::CalculatePath(FVector Start, FVector End)
{
    TArray<FVector> ResultPath;
 
    UNavigationSystemV1* NavSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
    if (NavSystem)
    {
        UNavigationPath* NavPath = NavSystem->FindPathToLocationSynchronously(GetWorld(), Start, End);
 
        if (NavPath && NavPath->IsValid())
        {
            ResultPath = NavPath->PathPoints;  // Automatically calculated and smoothed path
        }
    }
 
    return ResultPath;
}

float AAIPathfinding::Heuristic(FVector A, FVector B)
{
    return FVector::Dist(A, B);  // Euclidean distance as heuristic
}

TArray<FVector> AAIPathfinding::SmoothPath(TArray<FVector> Path)
{
    // Implement a smoothing algorithm (e.g., removing unnecessary waypoints)
    // For simplicity, returning the path as is for now
    return Path;
}
