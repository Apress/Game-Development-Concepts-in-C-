#include "NPCSystem.h"
#include "GameFramework/Character.h"

ANPCSystem::ANPCSystem()
{
    PrimaryActorTick.bCanEverTick = true;
    InteractionRadius = 200.0f;
    bIsPlayerNearby = false;
    NPCInteractionType = ENPCInteractionType::Dialogue; // Default interaction type
}

void ANPCSystem::BeginPlay()
{
    Super::BeginPlay();
}

void ANPCSystem::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    CheckProximity();
}

void ANPCSystem::CheckProximity()
{
    // Implement proximity detection logic here
    // Example: Check if the player is within the InteractionRadius
}

void ANPCSystem::Interact()
{
    if (bIsPlayerNearby)
    {
        ExecuteInteraction();
    }
}

void ANPCSystem::ExecuteInteraction()
{
    switch (NPCInteractionType)
    {
        case ENPCInteractionType::Dialogue:
            HandleDialogue();
            break;

        case ENPCInteractionType::Quest:
            HandleQuest();
            break;

        case ENPCInteractionType::Trade:
            HandleTrade();
            break;

        case ENPCInteractionType::Combat:
            HandleCombat();
            break;

        default:
            break;
    }

    EndInteraction();
}

void ANPCSystem::HandleDialogue()
{
    if (Dialogues.Num() > 0)
    {
        FString Dialogue = Dialogues[0];
        // Implement dialogue display logic here
    }
}

void ANPCSystem::HandleQuest()
{
    if (Quests.Num() > 0)
    {
        FString Quest = Quests[0];
        // Implement quest initiation logic here
    }
}

void ANPCSystem::HandleTrade()
{
    // Implement trade logic here (e.g., open trade UI)
}

void ANPCSystem::HandleCombat()
{
    // Implement combat engagement logic here (e.g., trigger attack behavior)
}

void ANPCSystem::EndInteraction()
{
    // Implement interaction conclusion logic here
    // Example: Resume gameplay
}
