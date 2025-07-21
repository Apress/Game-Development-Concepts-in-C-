 #include "EnemyAI.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISense_Sight.h"
 
AEnemyAI::AEnemyAI()
{
    PrimaryActorTick.bCanEverTick = true;
 
    bIsInCombat = false;
    CurrentPatrolIndex = 0;
 
    AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));
    SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
 
    SightConfig->SightRadius = 800.0f;
    SightConfig->LoseSightRadius = 1000.0f;
    SightConfig->PeripheralVisionAngleDegrees = 90.0f;
    SightConfig->SetMaxAge(5.0f);
    SightConfig->DetectionByAffiliation.bDetectEnemies = true;
    SightConfig->DetectionByAffiliation.bDetectFriendlies = false;
    SightConfig->DetectionByAffiliation.bDetectNeutrals = false;
 
    AIPerception->ConfigureSense(*SightConfig);
    AIPerception->SetDominantSense(SightConfig->GetSenseImplementation());
 
    AIPerception->OnTargetPerceptionUpdated.AddDynamic(this, &AEnemyAI::OnTargetPerceived);
}
 
void AEnemyAI::BeginPlay()
{
    Super::BeginPlay();
 
    PatrolPoints.Add(FVector(100, 100, 0));
    PatrolPoints.Add(FVector(300, 300, 0));
    PatrolPoints.Add(FVector(500, 100, 0));
 
    StartPatrolling();
}
 
void AEnemyAI::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
 
    if (!bIsInCombat)
    {
        // Optional: continue patrol logic or monitor movement
    }
 
    if (bIsInCombat)
    {
        // Execute combat logic
    }
}
 
void AEnemyAI::StartPatrolling()
{
    if (PatrolPoints.Num() > 0)
    {
        MoveToNextPatrolPoint();
    }
}
 
void AEnemyAI::MoveToNextPatrolPoint()
{
    if (PatrolPoints.IsValidIndex(CurrentPatrolIndex))
    {
        FVector PatrolPoint = PatrolPoints[CurrentPatrolIndex];
        AAIController* AIController = Cast<AAIController>(GetController());
 
        if (AIController)
        {
            AIController->MoveToLocation(PatrolPoint);
 
            CurrentPatrolIndex = (CurrentPatrolIndex + 1) % PatrolPoints.Num();
        }
    }
}
 
void AEnemyAI::EngageCombat()
{
    bIsInCombat = true;
 
    // You can now trigger combat logic like animation or attack here
}
 
void AEnemyAI::OnTargetPerceived(AActor* Actor, FAIStimulus Stimulus)
{
    if (Stimulus.WasSuccessfullySensed())
    {
        // Player detected
        EngageCombat();
    }
    else
    {
        // Player lost, resume patrol
        bIsInCombat = false;
        StartPatrolling();
    }
}
