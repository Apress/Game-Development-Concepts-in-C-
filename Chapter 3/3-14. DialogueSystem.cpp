#include "DialogueSystem.h"
#include "GameFramework/Actor.h"

ADialogueSystem::ADialogueSystem()
{
    PrimaryActorTick.bCanEverTick = true;
    CurrentDialogueIndex = 0;
}

void ADialogueSystem::BeginPlay()
{
    Super::BeginPlay();
}

void ADialogueSystem::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ADialogueSystem::StartDialogue()
{
    if (Dialogues.Num() > 0)
    {
        DisplayDialogue(CurrentDialogueIndex);
    }
}

void ADialogueSystem::DisplayDialogue(int32 Index)
{
    if (Index < Dialogues.Num())
    {
        // Implement dialogue display logic here
        // For example, show the dialogue text on screen

        // Check for player choices
        if (DialogueChoices.Contains(Dialogues[Index]))
        {
            FString PlayerChoice = DialogueChoices[Dialogues[Index]];
            HandlePlayerChoice(PlayerChoice);
        }
    }
}

void ADialogueSystem::HandlePlayerChoice(FString Choice)
{
    // Implement logic for handling player choices
    // For example, change the dialogue flow based on the choice
}

void ADialogueSystem::EndDialogue()
{
    // Implement dialogue conclusion logic here
    // For example, resume gameplay
}
