#include "AdvancedNPCSystem.h"
#include "GameFramework/Character.h"

AAdvancedNPCSystem::AAdvancedNPCSystem()
{
    PrimaryActorTick.bCanEverTick = true;
    InteractionRadius = 200.0f;
    bIsPlayerNearby = false;
    CurrentState = ENPCState::Idle; // Default state
}

void AAdvancedNPCSystem::BeginPlay()
{
    Super::BeginPlay();
}

void AAdvancedNPCSystem::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    CheckProximity();

    // Implement state-based behavior
    switch (CurrentState)
    {
    case ENPCState::Idle:
        // Idle behavior: NPC could roam, animate, or wait
        break;

    case ENPCState::Interacting:
        // Interacting behavior: NPC might perform a gesture or play an animation
        break;
    }
}

void AAdvancedNPCSystem::CheckProximity()
{
    // Implement proximity detection logic
    // Example: Check if the player is within InteractionRadius
}

void AAdvancedNPCSystem::Interact()
{
    if (bIsPlayerNearby)
    {
        ChangeState(ENPCState::Interacting);
        ExecuteInteraction();
    }
}

void AAdvancedNPCSystem::ExecuteInteraction()
{
    // Implement interaction logic (e.g., display dialogue or start a quest)

    if (Dialogues.Num() > 0)
    {
        FString Dialogue = Dialogues[0];
        // Implement dialogue display logic here
    }

    if (Quests.Num() > 0)
    {
        FString Quest = Quests[0];
        // Implement quest initiation logic here
    }

    EndInteraction();
}

void AAdvancedNPCSystem::ChangeState(ENPCState NewState)
{
    CurrentState = NewState;

    // Implement state change logic (e.g., play animation, update UI)
}

void AAdvancedNPCSystem::EndInteraction()
{
    ChangeState(ENPCState::Idle);
    // Implement logic to conclude the interaction
}
