#include "BranchingDialogueSystem.h"
#include "GameFramework/Actor.h"

ABranchingDialogueSystem::ABranchingDialogueSystem()
{
    PrimaryActorTick.bCanEverTick = true;
    CurrentDialogueIndex = 0;
}

void ABranchingDialogueSystem::BeginPlay()
{
    Super::BeginPlay();
}

void ABranchingDialogueSystem::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ABranchingDialogueSystem::StartDialogue()
{
    if (Dialogues.Num() > 0)
    {
        DisplayDialogue(CurrentDialogueIndex);
    }
}

void ABranchingDialogueSystem::DisplayDialogue(int32 Index)
{
    if (Index < Dialogues.Num())
    {
        // Implement dialogue display logic here
        // For example, show the dialogue text on screen

        // Check for branching choices
        if (BranchingChoices.Contains(Dialogues[Index]))
        {
            TArray<FString> Choices = BranchingChoices[Dialogues[Index]];
            for (const FString& Choice : Choices)
            {
                HandleBranchingChoice(Choice);
            }
        }
    }
}

void ABranchingDialogueSystem::HandleBranchingChoice(FString Choice)
{
    // Implement logic for handling branching choices
    // For example, change the dialogue flow based on the choice
}

void ABranchingDialogueSystem::EndDialogue()
{
    // Implement dialogue conclusion logic here
    // For example, resume gameplay
}
