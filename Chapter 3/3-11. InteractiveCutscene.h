#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractiveCutscene.generated.h"

UCLASS()
class MYGAME_API AInteractiveCutscene : public AActor
{
    GENERATED_BODY()
    
public:    
    AInteractiveCutscene();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;

    void StartCutscene();

private:
    UPROPERTY(EditAnywhere)
    AActor* CameraActor;

    UPROPERTY(EditAnywhere)
    TArray<AActor*> ActorsInCutscene;

    UPROPERTY(EditAnywhere)
    TArray<FString> Dialogues;

    UPROPERTY(EditAnywhere)
    TMap<FString, FString> DialogueChoices;

    void PlayDialogue(int32 Index);
    void EndCutscene();
    void HandlePlayerChoice(FString Choice);
};
