#include "EnvironmentalInteractionComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

UEnvironmentalInteractionComponent::UEnvironmentalInteractionComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UEnvironmentalInteractionComponent::BeginPlay()
{
    Super::BeginPlay();

    // Bind the TriggerExplosion function to an event or game action
    // Example: UFUNCTION() TriggeredBySpellCast();
    // Bind function: TriggeredBySpellCast.AddDynamic(this, &UEnvironmentalInteractionComponent::TriggerExplosion);
}

void UEnvironmentalInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UEnvironmentalInteractionComponent::TriggerExplosion()
{
    FVector Center = GetOwner()->GetActorLocation();

    // Apply explosion effects to surrounding objects or terrain
    DrawDebugSphere(GetWorld(), Center, 500.0f, 12, FColor::Blue, false, 2.0f);

    // Spawn a radial force component to simulate the explosion's force
    URadialForceComponent* RadialForce = NewObject<URadialForceComponent>(GetOwner());
    RadialForce->AttachToComponent(GetOwner()->GetRootComponent(), FAttachmentTransformRules::KeepWorldTransform);
    RadialForce->Radius = 500.0f; // Explosion radius
    RadialForce->ForceStrength = 1000.0f; // Explosion force strength
    RadialForce->bImpulseVelChange = true;
    RadialForce->FireImpulse();

    // Implement destruction logic using Chaos Destruction (for destructible objects)
    TArray<AActor*> OverlappingActors;
    GetOverlappingActors(OverlappingActors);

    for (AActor* Actor : OverlappingActors)
    {
        // Check if the actor has a Chaos Destructible Mesh component
        UChaosDestructibleComponent* DestructibleComponent = Cast<UChaosDestructibleComponent>(Actor->GetComponentByClass(UChaosDestructibleComponent::StaticClass()));
        if (DestructibleComponent)
        {
            // Apply destruction effect (e.g., trigger fracturing of the mesh)
            DestructibleComponent->ApplyDamage(100.0f, Center, FVector(1, 0, 0), 500.0f);
        }
    }
}
