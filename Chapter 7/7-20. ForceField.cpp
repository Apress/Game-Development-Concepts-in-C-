#include "ForceField.h"
#include "GameFramework/Actor.h"

AForceField::AForceField()
{
    PrimaryActorTick.bCanEverTick = true;
    ForceStrength = 500.0f;
    FieldRadius = 300.0f;
}

void AForceField::BeginPlay()
{
    Super::BeginPlay();
}

void AForceField::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    ApplyForceToObjects();
}

void AForceField::SetForceStrength(float NewStrength)
{
    ForceStrength = NewStrength;
}

void AForceField::SetFieldRadius(float NewRadius)
{
    FieldRadius = NewRadius;
}

void AForceField::ApplyForceToObjects()
{
    TArray<AActor*> OverlappingActors;
    GetOverlappingActors(OverlappingActors);

    for (AActor* Actor : OverlappingActors)
    {
        if (Actor->GetRootComponent() && Actor->GetRootComponent()->IsSimulatingPhysics())
        {
            FVector Direction = Actor->GetActorLocation() - GetActorLocation();
            float Distance = Direction.Size();

            if (Distance <= FieldRadius)
            {
                Direction.Normalize();
                FVector Force = Direction * ForceStrength * (1.0f - Distance / FieldRadius);
                Actor->GetRootComponent()->AddForce(Force);
            }
        }
    }
}
