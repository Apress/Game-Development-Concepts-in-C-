#include "InteractionParticleManager.h"
#include "Particles/ParticleSystem.h "
#include "Kismet/GameplayStatics.h"

AInteractionParticleManager::AInteractionParticleManager()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AInteractionParticleManager::BeginPlay()
{
    Super::BeginPlay();
}

void AInteractionParticleManager::SpawnParticleEffect(FVector Location, UParticleSystem* ParticleEffect)
{
    if (ParticleEffect)
    {
        UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ParticleEffect, Location);
    }
}
