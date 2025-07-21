#include "Cutscene.h"
#include "GameFramework/Actor.h"

ACutscene::ACutscene()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ACutscene::BeginPlay()
{
    Super::BeginPlay();
}

void ACutscene::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ACutscene::StartCutscene()
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

void ACutscene::PlayDialogue(int32 Index)
{
    if (Index < Dialogues.Num())
    {
        // Implement dialogue playback logic here
        // For example, display the dialogue on screen
    }
}

void ACutscene::EndCutscene()
{
    // Implement cutscene conclusion logic here
    // For example, switch the camera back to the player
}
