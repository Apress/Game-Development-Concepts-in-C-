#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EventChain.generated.h"

/**
 * 
 */
UCLASS()
class MYGAME_API UEventChain : public UObject
{
    GENERATED_BODY()

public:
    UEventChain();

    void StartEventChain();
    void AddEvent(float TimeDelay, FTimerDelegate TimerDelegate);

private:
    FTimerHandle EventTimerHandle;
    TArray<TTuple<float, FTimerDelegate>> EventSequence;

    void ExecuteEvent(int32 EventIndex);
};
