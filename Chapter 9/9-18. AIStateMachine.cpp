#include "AIStateMachine.h"

AAIStateMachine::AAIStateMachine()
{
    PrimaryActorTick.bCanEverTick = true;
    CurrentState = "Idle"; // Initial state
}

void AAIStateMachine::BeginPlay()
{
    Super::BeginPlay();
}

void AAIStateMachine::ChangeState(FString NewState)
{
    if (CurrentState != NewState)
    {
        CurrentState = NewState;
        // Add logic here to handle state transition effects (e.g., animations, behavior changes)
        UE_LOG(LogTemp, Warning, TEXT("State changed to: %s"), *CurrentState);
    }
}
