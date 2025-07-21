#include "AI_DecisionTree.h"
#include "Kismet/GameplayStatics.h"

AAI_DecisionTree::AAI_DecisionTree()
{
    PrimaryActorTick.bCanEverTick = true;
    bPlayerInSight = false;
    bPlayerTooClose = false;
}

void AAI_DecisionTree::BeginPlay()
{
    Super::BeginPlay();
}

void AAI_DecisionTree::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    MakeDecision();
}

 void AAI_DecisionTree::MakeDecision()
{
    AActor* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (!Player || !AIController || !AIController->GetBlackboardComponent())
        return;
 
    FVector PlayerLocation = Player->GetActorLocation();
    FVector AICharacterLocation = GetActorLocation();
    float Distance = FVector::Dist(PlayerLocation, AICharacterLocation);
 
    UBlackboardComponent* Blackboard = AIController->GetBlackboardComponent();
 
    bool bInSight = Distance < 1000.0f;
    bool bTooClose = Distance < 200.0f;
 
    Blackboard->SetValueAsBool(TEXT("bPlayerInSight"), bInSight);
    Blackboard->SetValueAsBool(TEXT("bPlayerTooClose"), bTooClose);
    Blackboard->SetValueAsVector(TEXT("PlayerLocation"), PlayerLocation);
}
