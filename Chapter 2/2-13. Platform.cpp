#include "Platform.h"
#include "Components/StaticMeshComponent.h"

APlatform::APlatform()
{
    PrimaryActorTick.bCanEverTick = true;

    PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
    RootComponent = PlatformMesh;

    PlatformMesh->SetMobility(EComponentMobility::Movable);
    PlatformMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    PlatformMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
}
