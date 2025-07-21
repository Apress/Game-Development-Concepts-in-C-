#include "InteractiveObject.h"
#include "Components/StaticMeshComponent.h"

AInteractiveObject::AInteractiveObject()
{
    PrimaryActorTick.bCanEverTick = true;

    ObjectMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ObjectMesh"));
    RootComponent = ObjectMesh;

    bIsInteractable = true;
}

void AInteractiveObject::OnInteract()
{
    if (bIsInteractable)
    {
        // Implement interaction logic here
    }
}
