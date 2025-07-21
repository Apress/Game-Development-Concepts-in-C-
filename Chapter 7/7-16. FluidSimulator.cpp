#include "FluidSimulator.h"

AFluidSimulator::AFluidSimulator()
{
    PrimaryActorTick.bCanEverTick = true;
    MaxParticles = 1000;
    ParticleRadius = 10.0f;
    Viscosity = 0.1f;
}

void AFluidSimulator::BeginPlay()
{
    Super::BeginPlay();
}

void AFluidSimulator::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    UpdateParticles(DeltaTime);
    RenderParticles();
}

void AFluidSimulator::AddParticle(const FVector& Position, const FVector& Velocity)
{
    if (ParticlePositions.Num() >= MaxParticles)
        return;

    ParticlePositions.Add(Position);
    ParticleVelocities.Add(Velocity);
}

void AFluidSimulator::UpdateParticles(float DeltaTime)
{
    for (int32 i = 0; i < ParticlePositions.Num(); i++)
    {
        FVector& Position = ParticlePositions[i];
        FVector& Velocity = ParticleVelocities[i];

        // Apply velocity
        Position += Velocity * DeltaTime;

        // Apply viscosity (dampening)
        Velocity *= 1.0f - Viscosity * DeltaTime;
    }
}

void AFluidSimulator::RenderParticles()
{
    for (const FVector& Position : ParticlePositions)
    {
        // Visualization logic (e.g., draw spheres at particle positions)
        DrawDebugSphere(GetWorld(), Position, ParticleRadius, 12, FColor::Blue, false, -1.0f);
    }
}
