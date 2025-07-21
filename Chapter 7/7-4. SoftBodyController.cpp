#include "SoftBodyController.h"

ASoftBodyController::ASoftBodyController()
{
    PrimaryActorTick.bCanEverTick = true;

    SpringConstant = 1000.0f;
    Damping = 0.1f;
}

void ASoftBodyController::BeginPlay()
{
    Super::BeginPlay();
    
    // Initialize the soft body with masses and velocities
    // For simplicity, we start with a few points that will represent the soft body
    Masses.Add(FVector(0, 0, 0)); // First mass point
    Masses.Add(FVector(100, 0, 0)); // Second mass point
    Velocities.Add(FVector(0, 0, 0)); // Initial velocity
    Velocities.Add(FVector(0, 0, 0)); // Initial velocity for second mass
}

void ASoftBodyController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    SimulateSoftBody(DeltaTime); // Simulate the soft body dynamics each frame
}

void ASoftBodyController::ApplyForce(FVector Force, int32 MassIndex)
{
    // Apply the force to the specified mass point
    if (MassIndex >= 0 && MassIndex < Masses.Num())
    {
        Velocities[MassIndex] += Force;
    }
}

void ASoftBodyController::SimulateSoftBody(float DeltaTime)
{
    // Simple spring-mass simulation: Calculate forces and update positions
    for (int32 i = 0; i < Masses.Num(); ++i)
    {
        FVector Force = FVector(0, 0, 0); // Reset the force for this mass

        // Apply spring force based on neighboring mass points (for simplicity)
        if (i < Masses.Num() - 1) // Check if there's a neighbor mass
        {
            FVector Direction = Masses[i + 1] - Masses[i];
            float Distance = Direction.Size();
            Direction.Normalize();
            
            float SpringForce = SpringConstant * (Distance - 100.0f); // Deformation from resting distance
            Force += Direction * SpringForce; // Apply force in the direction of the spring

            // Apply damping to the velocity
            Velocities[i] -= Velocities[i] * Damping;
        }

        // Update the mass position based on the force applied
        Masses[i] += Velocities[i] * DeltaTime; // Simple update: position += velocity * time
    }
}
