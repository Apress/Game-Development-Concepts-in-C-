#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BranchingDialogueSystem.generated.h"

UCLASS()
class MYGAME_API ABranchingDialogueSystem : public AActor
{
    GENERATED_BODY()
    
public:    
    ABranchingDialogueSystem();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;

    void StartDialogue();

private:
    UPROPERTY(EditAnywhere)
    TArray<FString> Dialogues;

    UPROPERTY(EditAnywhere)
    TMap<FString, TArray<FString>> BranchingChoices;

    int32 CurrentDialogueIndex;

    void DisplayDialogue(int32 Index);
    void HandleBranchingChoice(FString Choice);
    void EndDialogue();
};
