#include "InteractiveObject.h"
#include "Components/StaticMeshComponent.h"

AInteractiveObject::AInteractiveObject()
{
    PrimaryActorTick.bCanEverTick = true;

    ObjectMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ObjectMesh"));
    RootComponent = ObjectMesh;
    bIsActive = false;
}

void AInteractiveObject::BeginPlay()
{
    Super::BeginPlay();
}

void AInteractiveObject::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AInteractiveObject::Interact()
{
    // If the object is already active, deactivate it and exit the function

    if (bIsActive)
    {
        bIsActive = false;  // Deactivate object (e.g., close door, disable trap)
        return;  // Exit as no further actions are needed
    }

    // If the object is not active, activate it

    bIsActive = true;  // Activate object (e.g., open door, trigger trap)

    // Implement activation logic here
}
