#include "ComplexInteractionSystem.h"
#include "InteractiveObject.h"

UComplexInteractionSystem::UComplexInteractionSystem()
{
}

void UComplexInteractionSystem::AddInteractiveObject(AInteractiveObject* InteractiveObject)
{
    InteractiveObjects.Add(InteractiveObject);
}

void UComplexInteractionSystem::HandleInteraction(FString InteractionType)
{
    // Implement interaction handling logic here
}
