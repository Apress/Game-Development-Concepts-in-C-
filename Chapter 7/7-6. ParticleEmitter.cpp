#include "ParticleEmitter.h"

AParticleEmitter::AParticleEmitter()
{
    PrimaryActorTick.bCanEverTick = true;
    MaxParticles = 100;
    ParticleLifetime = 5.0f;
    ParticleVelocity = FVector(0.0f, 0.0f, 1.0f);  // Particles will move upwards initially
}

void AParticleEmitter::BeginPlay()
{
    Super::BeginPlay();
    
    // Initialize the particle arrays
    Particles.SetNum(MaxParticles);
    Lifetimes.SetNum(MaxParticles);
}

void AParticleEmitter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Emit new particles
    EmitParticle();

    // Update particle positions and lifetimes
    UpdateParticles(DeltaTime);
}

void AParticleEmitter::EmitParticle()
{
    for (int32 i = 0; i < MaxParticles; i++)
    {
        if (Lifetimes[i] <= 0.0f)
        {
            Particles[i] = GetActorLocation();  // Set new particle position at emitter
            Lifetimes[i] = ParticleLifetime;   // Reset lifetime
        }
    }
}

void AParticleEmitter::UpdateParticles(float DeltaTime)
{
    for (int32 i = 0; i < MaxParticles; i++)
    {
        if (Lifetimes[i] > 0.0f)
        {
            Particles[i] += ParticleVelocity * DeltaTime;  // Update particle position
            Lifetimes[i] -= DeltaTime;  // Decrease particle lifetime
        }
    }
}
