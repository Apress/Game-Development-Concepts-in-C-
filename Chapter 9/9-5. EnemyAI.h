 #pragma once
 
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Perception/AIPerceptionTypes.h"
#include "EnemyAI.generated.h"
 
class UAIPerceptionComponent;
class UAISenseConfig_Sight;
 
UCLASS()
class MYGAME_API AEnemyAI : public ACharacter
{
    GENERATED_BODY()
 
public:
    AEnemyAI();
 
protected:
    virtual void BeginPlay() override;
 
public:
    virtual void Tick(float DeltaTime) override;
 
    void StartPatrolling();
    void EngageCombat();
 
private:
    TArray<FVector> PatrolPoints;
    int32 CurrentPatrolIndex;
    bool bIsInCombat;
 
    void MoveToNextPatrolPoint();
 
    // Perception system
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI", meta = (AllowPrivateAccess = "true"))
    UAIPerceptionComponent* AIPerception;
 
    UPROPERTY()
    UAISenseConfig_Sight* SightConfig;
 
    UFUNCTION()
    void OnTargetPerceived(AActor* Actor, FAIStimulus Stimulus);
};

