#include "DestructibleComponent.h"
#include "Kismet/GameplayStatics.h"

UDestructibleComponent::UDestructibleComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    DamageThreshold = 50.0f;
    bIsDestroyed = false;
}

void UDestructibleComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UDestructibleComponent::ApplyDamage(float Damage, const FVector& HitLocation)
{
    if (bIsDestroyed)
        return;

    if (Damage >= DamageThreshold)
    {
        DestroyObject();
    }
}

void UDestructibleComponent::DestroyObject()
{
    if (bIsDestroyed)
        return;

    bIsDestroyed = true;

    // Simulate destruction (e.g., spawn debris, play sound effects)
    UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), DestructionEffect, GetOwner()->GetActorLocation());
    GetOwner()->Destroy();
}

