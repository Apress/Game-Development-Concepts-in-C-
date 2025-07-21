#include "ParticleCollision.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/ParticleSystem.h"
#include "Components/PrimitiveComponent.h"

AParticleCollision::AParticleCollision()
{
    PrimaryActorTick.bCanEverTick = true;

    CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
    RootComponent = CollisionBox;

    ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
    ParticleSystem->SetupAttachment(RootComponent);

    CollisionParticles = nullptr; // Set the particle system to be assigned in the editor

    CollisionBox->OnComponentHit.AddDynamic(this, &AParticleCollision::OnObjectCollision);
}

void AParticleCollision::OnObjectCollision(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    if (CollisionParticles)
    {
        UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), CollisionParticles, Hit.ImpactPoint);
    }
}
