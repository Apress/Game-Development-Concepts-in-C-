#include "PushbackComponent.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/Controller.h"
#include "Components/CapsuleComponent.h"

UPushbackComponent::UPushbackComponent()
{
    PrimaryComponentTick.bCanEverTick = true;

    PushbackForce = 500.0f;
}

void UPushbackComponent::BeginPlay()
{
    Super::BeginPlay();

    // Bind the ApplyPushback function to a trigger event or game action
    // Example: UFUNCTION() TriggeredByEnvironmentalForce();
    // Bind function: TriggeredByEnvironmentalForce.AddDynamic(this, &UPushbackComponent::ApplyPushback);
}

void UPushbackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UPushbackComponent::ApplyPushback(FVector PushbackDirection)
{
    ACharacter* Character = Cast<ACharacter>(GetOwner());
    if (Character && Character->GetController())
    {
	USkeletalMeshComponent* TargetMesh = Character->GetMesh(); 
	if (!TargetMesh || PushbackDirection.IsZero()) 
		{return;} // Exit if no mesh is found or pushback direction is zero

        // Apply force to push character in the specified direction
        FVector PushbackVelocity = PushbackDirection * PushbackForce;
        Character->LaunchCharacter(PushbackVelocity, true, true);
    }
}
