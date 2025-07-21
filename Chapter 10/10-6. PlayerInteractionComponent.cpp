#include "PlayerInteractionComponent.h"
#include "Net/UnrealNetwork.h"

UPlayerInteractionComponent::UPlayerInteractionComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UPlayerInteractionComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UPlayerInteractionComponent::Server_Interact_Implementation(AActor* TargetActor)
{
    if (TargetActor)
    {
        // Perform interaction logic
        Multicast_PlayInteractionEffect(TargetActor);
    }
}

bool UPlayerInteractionComponent::Server_Interact_Validate(AActor* TargetActor)
{
    return true;
}

void UPlayerInteractionComponent::Multicast_PlayInteractionEffect(AActor* TargetActor)
{
    if (TargetActor)
    {
        // Play visual or sound effect here
    }
}
