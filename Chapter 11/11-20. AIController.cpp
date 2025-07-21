#include "AdaptiveAIController.h"
#include "GameFramework/Actor.h"

void AAdaptiveAIController::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("Adaptive AI Initialized!"));
}

void AAdaptiveAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    AdjustBehaviorBasedOnPlayer();
}

void AAdaptiveAIController::AdjustBehaviorBasedOnPlayer()
{
    // Example logic: Change NPC behavior based on player's actions
    AActor* Player = GetWorld()->GetFirstPlayerController()->GetPawn();
    if (Player)
    {
        FVector PlayerLocation = Player->GetActorLocation();
        FVector NPCLocation = GetPawn()->GetActorLocation();

        float Distance = FVector::Dist(PlayerLocation, NPCLocation);
        if (Distance < 500.0f)
        {
            UE_LOG(LogTemp, Warning, TEXT("Player is nearby! Switching to aggressive behavior."));
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Player is far away! Patrolling."));
        }
    }
}
