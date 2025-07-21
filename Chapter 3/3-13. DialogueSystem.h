#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DialogueSystem.generated.h"

UCLASS()
class MYGAME_API ADialogueSystem : public AActor
{
    GENERATED_BODY()
    
public:    
    ADialogueSystem();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;

    void StartDialogue();

private:
    UPROPERTY(EditAnywhere)
    TArray<FString> Dialogues;

    UPROPERTY(EditAnywhere)
    TMap<FString, FString> DialogueChoices;

    int32 CurrentDialogueIndex;

    void DisplayDialogue(int32 Index);
    void HandlePlayerChoice(FString Choice);
    void EndDialogue();
};
