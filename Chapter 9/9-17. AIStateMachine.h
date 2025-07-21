#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AIStateMachine.generated.h"

UCLASS()
class MYGAME_API AAIStateMachine : public AActor
{
    GENERATED_BODY()

public:
    AAIStateMachine();

    UFUNCTION(BlueprintCallable, Category = "AI State")
    void ChangeState(FString NewState);

protected:
    virtual void BeginPlay() override;
    
private:
    FString CurrentState;
};
