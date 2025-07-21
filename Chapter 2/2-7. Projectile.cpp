#include "Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"

AProjectile::AProjectile()
{
    PrimaryActorTick.bCanEverTick = true;

    ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
    RootComponent = ProjectileMesh;

    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
    ProjectileMovement->bShouldBounce = true;

    ProjectileMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
}

void AProjectile::BeginPlay()
{
    Super::BeginPlay();
}

void AProjectile::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
    // Implement deflection logic here
}
