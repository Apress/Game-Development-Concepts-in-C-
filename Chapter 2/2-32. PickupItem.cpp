#include "PickupItem.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h
#include "PlayerCharacter.h"

APickupItem::APickupItem()
{
    PrimaryActorTick.bCanEverTick = true;

    PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
    RootComponent = PickupMesh;

    CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
    CollisionSphere->SetupAttachment(RootComponent);
    CollisionSphere->SetSphereRadius(PickupRadius);
    CollisionSphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    CollisionSphere->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);

    bIsPickupable = true;
}

void APickupItem::BeginPlay()
{
    Super::BeginPlay();
    CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &APickupItem::OnPlayerPickup);
}

void APickupItem::OnPlayerPickup(APlayerCharacter* Player)
{
    if (bIsPickupable)
    {
        // Add logic here to apply effects or modify player state upon pickup
        bIsPickupable = false;
        Destroy();
    }
}
