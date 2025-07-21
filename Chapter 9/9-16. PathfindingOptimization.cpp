#include "PathfindingOptimization.h"
#include "NavigationSystem.h"
#include "GameFramework/Actor.h"
#include "AIController.h"
#include "NavigationPath.h"

APathfindingOptimization::APathfindingOptimization()
{
    PrimaryActorTick.bCanEverTick = false;
}

void APathfindingOptimization::BeginPlay()
{
    Super::BeginPlay();
    NavSystem = UNavigationSystemV1::GetCurrent(GetWorld());
}

void APathfindingOptimization::FindOptimizedPath(FVector StartLocation, FVector EndLocation)
{
    if (NavSystem)
    {
        FNavLocation StartNavLocation;
        FNavLocation EndNavLocation;

        if (NavSystem->ProjectPointToNavigation(StartLocation, StartNavLocation) &&
            NavSystem->ProjectPointToNavigation(EndLocation, EndNavLocation))
        {
            // Request the path from the navigation system
            UNavigationPath* Path = NavSystem->FindPathToLocationSynchronously(GetWorld(), StartNavLocation.Location, EndNavLocation.Location);

            if (Path && Path->IsValid())
            {
                // Move the AI along the path
                AAIController* AIController = Cast<AAIController>(GetController());
                if (AIController)
                {
                    AIController->MoveToLocation(EndNavLocation.Location);
                }
            }
        }
    }
}
