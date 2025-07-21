#include "DirectionalInfluenceComponent.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Character.h"

UDirectionalInfluenceComponent::UDirectionalInfluenceComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UDirectionalInfluenceComponent::BeginPlay()
{
    Super::BeginPlay();

    // Bind the ApplyDirectionalInfluence function to a trigger event or game action
    // Example: UFUNCTION() TriggeredByPlayerInput();
    // Bind function: TriggeredByPlayerInput.AddDynamic(this, &UDirectionalInfluenceComponent::ApplyDirectionalInfluence);
}

void UDirectionalInfluenceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UDirectionalInfluenceComponent::ApplyDirectionalInfluence(FVector Direction)
{
    ACharacter* Character = Cast<ACharacter>(GetOwner());
    if (Character)
    {
        // Modify the knockback direction based on player input direction
        // Example: Calculate modified knockback velocity using Direction vector
        FVector ModifiedKnockbackVelocity = Direction * Character->LaunchCharacterMaxForce;
        Character->LaunchCharacter(ModifiedKnockbackVelocity, true, true);
    }
}
