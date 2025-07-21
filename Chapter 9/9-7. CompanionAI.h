#pragma once
 
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NavigationSystem.h"
#include "CompanionAI.generated.h"
 
UCLASS()
class MYGAME_API ACompanionAI : public ACharacter
{
    GENERATED_BODY()
 
public:
    ACompanionAI();
 
protected:
    virtual void BeginPlay() override;
 
public:
    virtual void Tick(float DeltaTime) override;
 
    void FollowPlayer();
    void AssistInCombat(AActor* EnemyTarget);
    void StayInPlace();
 
private:
    FVector TargetLocation;
    AActor* PlayerActor;
    AActor* CurrentEnemyTarget;
 
    void MoveToLocation(FVector Location);
};
