#include "InteractiveCutscene.h"
#include "GameFramework/Actor.h"

AInteractiveCutscene::AInteractiveCutscene()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AInteractiveCutscene::BeginPlay()
{
    Super::BeginPlay();
}

void AInteractiveCutscene::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AInteractiveCutscene::StartCutscene()
{
    if (CameraActor)
    {
        // Set the camera view to CameraActor
        // Implement camera control logic here
    }

    for (int32 i = 0; i < Dialogues.Num(); i++)
    {
        PlayDialogue(i);
    }

    EndCutscene();
}

void AInteractiveCutscene::PlayDialogue(int32 Index)
{
    if (Index < Dialogues.Num())
    {
        // Implement dialogue playback logic here
        // For example, display the dialogue on screen

        // Check for player choices
        if (DialogueChoices.Contains(Dialogues[Index]))
        {
            FString PlayerChoice = DialogueChoices[Dialogues[Index]];
            HandlePlayerChoice(PlayerChoice);
        }
    }
}

void AInteractiveCutscene::HandlePlayerChoice(FString Choice)
{
    // Implement logic for handling player choices
    // For example, change the cutscene outcome based on the choice
}

void AInteractiveCutscene::EndCutscene()
{
    // Implement cutscene conclusion logic here
    // For example, switch the camera back to the player
}
