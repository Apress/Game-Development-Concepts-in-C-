#pragma once  

#include "CoreMinimal.h"  
#include "AIController.h"  
#include "BossAIController.generated.h"  

UCLASS()  
class MYGAME_API ABossAIController : public AAIController  
{  
    GENERATED_BODY()  

public:  
    ABossAIController();  

    virtual void Tick(float DeltaTime) override;  

    UFUNCTION(BlueprintCallable, Category = "Boss")  
    void PerformAttack();  

private:  
    bool bIsInAttackRange;  
};
