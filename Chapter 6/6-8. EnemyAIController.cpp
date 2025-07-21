#include "EnemyAIController.h"
#include "Kismet/GameplayStatics.h"

AEnemyAIController::AEnemyAIController()
{
    PrimaryActorTick.bCanEverTick = true;
    Health = 100.0f;
    bPlayerInRange = false;
    bCanAttack = true;
    bCanEvade = true;
    CurrentState = "Idle";
}

void AEnemyAIController::BeginPlay()
{
    Super::BeginPlay();
}

void AEnemyAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Check for player proximity
    AActor* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
    if (Player)
    {
        FVector PlayerLocation = Player->GetActorLocation();
        FVector EnemyLocation = GetActorLocation();
        float Distance = FVector::Dist(PlayerLocation, EnemyLocation);

        if (Distance < 500.0f) // Player is within range
        {
            bPlayerInRange = true;
        }
        else
        {
            bPlayerInRange = false;
        }

        // Decision making based on health and proximity
        if (bPlayerInRange)
        {
            if (Health < 30.0f && bCanEvade)
            {
                ChangeState("Evading");
            }
            else if (bCanAttack)
            {
                ChangeState("Attacking");
            }
        }
        else
        {
            ChangeState("Idle");
        }
    }
}

void AEnemyAIController::ChangeState(FString NewState)
{
    if (CurrentState != NewState)
    {
        CurrentState = NewState;

        if (CurrentState == "Attacking")
        {
            // Execute attacking behavior (e.g., animation, damage)
        }
        else if (CurrentState == "Evading")
        {
            // Execute evading behavior (e.g., moving away from player)
        }
        else if (CurrentState == "Idle")
        {
            // Execute idle behavior (e.g., patrolling or standing still)
        }
    }
}
