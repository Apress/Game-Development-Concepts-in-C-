#include "RopePhysicsComponent.h"

URopePhysicsComponent::URopePhysicsComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    NumNodes = 10;
    NodeMass = 1.0f;
    SpringStiffness = 100.0f;
}

void URopePhysicsComponent::BeginPlay()
{
    Super::BeginPlay();

    // Initialize rope nodes
    for (int32 i = 0; i < NumNodes; ++i)
    {
        FNode Node;
        Node.Position = GetOwner()->GetActorLocation() + FVector(0, 0, -i * 10.0f);
        Node.Velocity = FVector::ZeroVector;
        RopeNodes.Add(Node);
    }
}

void URopePhysicsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    SimulateRope(DeltaTime);
}

void URopePhysicsComponent::SimulateRope(float DeltaTime)
{
    ApplyForces(DeltaTime);
    EnforceConstraints();
}

void URopePhysicsComponent::ApplyForces(float DeltaTime)
{
    for (FNode& Node : RopeNodes)
    {
        FVector Gravity = FVector(0, 0, -980.0f); // Gravity force
        Node.Velocity += (Gravity / NodeMass) * DeltaTime;
        Node.Position += Node.Velocity * DeltaTime;
    }
}

void URopePhysicsComponent::EnforceConstraints()
{
    for (int32 i = 1; i < RopeNodes.Num(); ++i)
    {
        FVector& CurrentPosition = RopeNodes[i].Position;
        FVector& PreviousPosition = RopeNodes[i - 1].Position;

        FVector Direction = (CurrentPosition - PreviousPosition).GetSafeNormal();
        float Distance = FVector::Dist(CurrentPosition, PreviousPosition);
        float Correction = (Distance - 10.0f) * SpringStiffness;

        FVector CorrectionVector = Direction * Correction;
        CurrentPosition -= CorrectionVector * 0.5f;
        PreviousPosition += CorrectionVector * 0.5f;
    }
}
