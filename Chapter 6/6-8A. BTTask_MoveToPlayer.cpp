#include "BTTask_MoveToPlayer.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Actor.h"

UBTTask_MoveToPlayer::UBTTask_MoveToPlayer()
{
    NodeName = "Move To Player";
    bNotifyTick = false;

    TargetActorKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTTask_MoveToPlayer, TargetActorKey), AActor::StaticClass());
}

EBTNodeResult::Type UBTTask_MoveToPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    AAIController* AICon = OwnerComp.GetAIOwner();
    if (!AICon)
    {
        return EBTNodeResult::Failed;
    }

    UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
    AActor* Target = Cast<AActor>(BlackboardComp->GetValueAsObject(TargetActorKey.SelectedKeyName));

    if (!Target)
    {
        return EBTNodeResult::Failed;
    }

    AICon->MoveToActor(Target, 5.0f);
    return EBTNodeResult::Succeeded;
}
