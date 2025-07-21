#include "DynamicPushbackComponent.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Character.h"

UDynamicPushbackComponent::UDynamicPushbackComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UDynamicPushbackComponent::BeginPlay()
{
    Super::BeginPlay();

    // Bind the ApplyDynamicPushback function to a trigger event or game action
    // Example: UFUNCTION() TriggeredByEvent();
    // Bind function: TriggeredByEvent.AddDynamic(this, &UDynamicPushbackComponent::ApplyDynamicPushback);
}

void UDynamicPushbackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UDynamicPushbackComponent::ApplyDynamicPushback(FVector PushbackDirection, float Intensity)
{
    ACharacter* Character = Cast<ACharacter>(GetOwner());
    if (Character)
    {
	USkeletalMeshComponent* TargetMesh = Character->GetMesh(); 
	if (!TargetMesh || PushbackDirection.IsZero()) 
		{return;} // Exit if no mesh is found or pushback direction
	is zero

        // Apply force to push character with adjusted intensity and direction
	
        FVector DynamicPushbackVelocity = PushbackDirection * Intensity;
        Character->LaunchCharacter(DynamicPushbackVelocity, true, true);
    }
}
