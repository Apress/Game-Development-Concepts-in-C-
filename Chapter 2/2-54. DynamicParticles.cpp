#include "DynamicParticles.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/ParticleSystem.h"

UDynamicParticles::UDynamicParticles()
{
    ImpactParticles = nullptr; // Set the particle system to be assigned in the editor
    MaxEmissionRate = 100.0f;
    ParticleDirection = FVector(1.0f, 0.0f, 0.0f);
}

void UDynamicParticles::AdjustParticleEffects(float CollisionIntensity, FVector CollisionDirection)
{
    if (ImpactParticles)
    {
        float EmissionRate = FMath::Lerp(0.0f, MaxEmissionRate, CollisionIntensity);
        ParticleDirection = CollisionDirection;

        // Modify particle system parameters based on collision intensity and direction
        // Adjust particle emission rates, colors, trajectories, or dynamic properties
    }
}
