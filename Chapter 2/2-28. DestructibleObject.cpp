#include "DestructibleObject.h"
#include "Components/StaticMeshComponent.h"


ADestructibleObject::ADestructibleObject()
{
    PrimaryActorTick.bCanEverTick = true;

    DestructibleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DestructibleMesh"));
    RootComponent = DestructibleMesh;

    MaxHealth = 100.0f;
    CurrentHealth = MaxHealth;
}

void ADestructibleObject::BeginPlay()
{
    Super::BeginPlay();
}

void ADestructibleObject::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ADestructibleObject::TakeDamage(float DamageAmount)
{
    CurrentHealth -= DamageAmount;
    if (CurrentHealth <= 0)
    {
        DestroyObject();
    }
}

void ADestructibleObject::DestroyObject()
{
    // Implement destruction effects and remove object from game world
    Destroy();
}
