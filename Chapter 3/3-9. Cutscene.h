#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cutscene.generated.h"

UCLASS()
class MYGAME_API ACutscene : public AActor
{
    GENERATED_BODY()
    
public:    
    ACutscene();

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

    void PlayDialogue(int32 Index);
    void EndCutscene();
};
