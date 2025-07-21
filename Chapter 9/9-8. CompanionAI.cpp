
 #include "CompanionAI.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "NavigationSystem.h"
#include "AIController.h"
 
ACompanionAI::ACompanionAI()
{
    PrimaryActorTick.bCanEverTick = true;
}
 
void ACompanionAI::BeginPlay()
{
    Super::BeginPlay();
 
    PlayerActor = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
}
 
void ACompanionAI::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
 
    if (PlayerActor)
    {
        FollowPlayer();
    }
}
 
void ACompanionAI::FollowPlayer()
{
    if (PlayerActor)
    {
        TargetLocation = PlayerActor->GetActorLocation() - FVector(200, 200, 0); // Avoid overlapping
        MoveToLocation(TargetLocation);
    }
}
 
void ACompanionAI::AssistInCombat(AActor* EnemyTarget)
{
    if (EnemyTarget)
    {
        CurrentEnemyTarget = EnemyTarget;
        MoveToLocation(EnemyTarget->GetActorLocation());
 
        // Optional: Add attack logic here
    }
}
 
void ACompanionAI::StayInPlace()
{
    AAIController* AIController = Cast<AAIController>(GetController());
    if (AIController)
    {
        AIController->StopMovement();
    }
}
 
void ACompanionAI::MoveToLocation(FVector Location)
{
    AAIController* AIController = Cast<AAIController>(GetController());
    if (AIController)
    {
        AIController->MoveToLocation(Location);
    }
}
