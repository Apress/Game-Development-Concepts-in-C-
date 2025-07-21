#include "KnockbackComponent.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/Controller.h"
#include "Components/CapsuleComponent.h"

UKnockbackComponent::UKnockbackComponent()
{
    PrimaryComponentTick.bCanEverTick = true;

    KnockbackForce = 1000.0f;
    StunDuration = 1.0f;
}

void UKnockbackComponent::BeginPlay()
{
    Super::BeginPlay();

    // Bind the ApplyKnockback function to a trigger event or game action
    // Example: UFUNCTION() TriggeredByStrongAttack();
    // Bind function: TriggeredByStrongAttack.AddDynamic(this, &UKnockbackComponent::ApplyKnockback);
}

void UKnockbackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UKnockbackComponent::ApplyKnockback(FVector KnockbackDirection)
{
    ACharacter* Character = Cast<ACharacter>(GetOwner());
    if (Character && Character->GetController())
    {
        // Apply force to push character in the specified direction
        FVector KnockbackVelocity = KnockbackDirection * KnockbackForce;
        
        // Check if the character's mesh is simulating physics
        USkeletalMeshComponent* TargetMesh = Character->GetMesh();
        if (TargetMesh && TargetMesh->IsSimulatingPhysics())
        {
            // If simulating physics, apply impulse instead of launching
            TargetMesh->AddImpulse(KnockbackVelocity, NAME_None, true);
        }
        else
        {
            // Otherwise, use the LaunchCharacter function to apply knockback
            Character->LaunchCharacter(KnockbackVelocity, true, true);
        }

        // Stun the character for a specified duration
        Character->DisableInput(Character->GetController());
        GetWorld()->GetTimerManager().SetTimer(TimerHandle_Stun, this, &UKnockbackComponent::EndStun, StunDuration, false);
    }
}

void UKnockbackComponent::EndStun()
{
    ACharacter* Character = Cast<ACharacter>(GetOwner());
    if (Character && Character->GetController())
    {
        // Re-enable character input after stun duration expires
        Character->EnableInput(Character->GetController());
    }
}
