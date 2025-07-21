#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyAIController.generated.h"

UCLASS()
class MYGAME_API AEnemyAIController : public AActor
{
    GENERATED_BODY()

public:
    AEnemyAIController();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    float Health;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    bool bPlayerInRange;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    bool bCanAttack;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    bool bCanEvade;

    UFUNCTION(BlueprintCallable, Category = "AI")
    void ChangeState(FString NewState);

private:
    FString CurrentState;
};
