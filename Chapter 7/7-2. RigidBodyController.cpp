#include "RigidBodyController.h"
#include "Components/StaticMeshComponent.h"
 
ARigidBodyController::ARigidBodyController()
{
    PrimaryActorTick.bCanEverTick = true;
 
    // Set up mesh and enable physics
    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    RootComponent = MeshComponent;
    MeshComponent->SetSimulatePhysics(true); // Physics will now handle gravity, velocity, mass, etc.
}
 
void ARigidBodyController::BeginPlay()
{
    Super::BeginPlay();
}
 
void ARigidBodyController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    // No need to manually apply gravity here; it's automatic
}
 
void ARigidBodyController::ApplyForce(const FVector& Force)
{
    if (MeshComponent && MeshComponent->IsSimulatingPhysics())
    {
        MeshComponent->AddForce(Force);
    }
}
