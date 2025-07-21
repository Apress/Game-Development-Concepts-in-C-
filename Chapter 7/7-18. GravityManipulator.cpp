#include "GravityManipulator.h"
#include "GameFramework/Actor.h"

AGravityManipulator::AGravityManipulator()
{
    PrimaryActorTick.bCanEverTick = true;
    GravityDirection = FVector(0.0f, 0.0f, -1.0f);
    GravityStrength = 980.0f; // Default gravity strength in cm/s²
}

void AGravityManipulator::BeginPlay()
{
    Super::BeginPlay();
}

void AGravityManipulator::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    ApplyGravity();
}

void AGravityManipulator::SetGravity(const FVector& NewDirection, float NewStrength)
{
    GravityDirection = NewDirection.GetSafeNormal(); // Normalize the direction vector
    GravityStrength = NewStrength;
}

void AGravityManipulator::ApplyGravity()
{
    for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
    {
        AActor* Actor = *ActorItr;

        if (Actor && Actor->GetRootComponent() && Actor->GetRootComponent()->IsSimulatingPhysics())
        {
            FVector Force = GravityDirection * GravityStrength * Actor->GetRootComponent()->GetMass();
            Actor->GetRootComponent()->AddForce(Force);
        }
    }
}
