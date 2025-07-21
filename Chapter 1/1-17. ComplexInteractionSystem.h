#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ComplexInteractionSystem.generated.h"

UCLASS()
class MYGAME_API UComplexInteractionSystem : public UObject
{
    GENERATED_BODY()

public:
    UComplexInteractionSystem();

    void AddInteractiveObject(AInteractiveObject* InteractiveObject);
    void HandleInteraction(FString InteractionType);

private:
    TArray<AInteractiveObject*> InteractiveObjects;
    TMap<FString, bool> InteractionStates;
};
