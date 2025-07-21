#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_MoveToPlayer.generated.h"

UCLASS()
class MYGAME_API UBTTask_MoveToPlayer : public UBTTaskNode
{
    GENERATED_BODY()

public:
    UBTTask_MoveToPlayer();

    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
    UPROPERTY(EditAnywhere, Category = "Blackboard")
    struct FBlackboardKeySelector TargetActorKey;
};
