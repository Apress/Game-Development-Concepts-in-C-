#include "ChainReactionComponent.h"
#include "Components/ActorComponent.h"
#include "DestructibleObject.h"


void UChainReactionComponent::BeginPlay()
{
    Super::BeginPlay();

    // Bind the TriggerChainReaction function to a trigger event or game action
    // Example: UFUNCTION() TriggeredByExplosion();
    // Bind function: TriggeredByExplosion.AddDynamic(this, &UChainReactionComponent::TriggerChainReaction);
}

void UChainReactionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UChainReactionComponent::TriggerChainReaction()
{
    TArray<AActor*> NearbyObjects;
    GetOwner()->GetOverlappingActors(NearbyObjects, ADestructibleObject::StaticClass());

    // Check if there are no objects in the array
    if (NearbyObjects.Num() < 1) 
    {
        return; // Exit if no nearby destructible objects
    }

    for (AActor* Object : NearbyObjects)
    {
        if (Object) // Ensure that the object is valid
        {
            ADestructibleObject* Destructible = Cast<ADestructibleObject>(Object);
            if (Destructible && Destructible != GetOwner())
            {
                Destructible->TakeDamage(50.0f); // Example damage amount
            }
        }
    }
}
