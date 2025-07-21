#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sound/SoundCue.h"
#include "DialogueManager.generated.h"

UCLASS()
class MYGAME_API ADialogueManager : public AActor
{
    GENERATED_BODY()

public:
    ADialogueManager();

    UFUNCTION(BlueprintCallable, Category = "Dialogue")
    void PlayDialogue(USoundCue* DialogueCue);

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(EditAnywhere, Category = "Dialogue")
    USoundCue* DefaultDialogue;

    UFUNCTION()
    void HandleDialogueFinished();
};
