#include "DialogueManager.h"
#include "Kismet/GameplayStatics.h"

ADialogueManager::ADialogueManager()
{
    PrimaryActorTick.bCanEverTick = false;
}

void ADialogueManager::BeginPlay()
{
    Super::BeginPlay();
}

void ADialogueManager::PlayDialogue(USoundCue* DialogueCue)
{
    if (!DialogueCue && DefaultDialogue)
    {
        DialogueCue = DefaultDialogue;
    }

    if (DialogueCue)
    {
        UGameplayStatics::PlaySound2D(this, DialogueCue);
        FTimerHandle TimerHandle;
        GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ADialogueManager::HandleDialogueFinished, DialogueCue->GetDuration(), false);
    }
}

void ADialogueManager::HandleDialogueFinished()
{
    UE_LOG(LogTemp, Log, TEXT("Dialogue finished playing."));
}
