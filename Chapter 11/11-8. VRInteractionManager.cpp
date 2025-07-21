#include "VRInteractionManager.h"
#include "GameFramework/Actor.h"
#include "Components/PrimitiveComponent.h"

AVRInteractionManager::AVRInteractionManager()
{
    PrimaryActorTick.bCanEverTick = true;

    MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionController"));
    RootComponent = MotionController;
}

void AVRInteractionManager::BeginPlay()
{
    Super::BeginPlay();
}

 void AVRInteractionManager::GrabObject()
{
    FVector Location = MotionController->GetComponentLocation();
    FHitResult Hit;
 
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(this);
 
    if (GetWorld()->LineTraceSingleByChannel(Hit, Location, Location + MotionController->GetForwardVector() * 200.0f, ECC_Visibility, Params))
    {
        GrabbedObject = Hit.GetActor();
 
        if (GrabbedObject)
        {
            UPrimitiveComponent* Primitive = Cast<UPrimitiveComponent>(GrabbedObject->GetRootComponent());
            if (Primitive)
            {
                Primitive->SetSimulatePhysics(false);
                GrabbedObject->AttachToComponent(MotionController, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
            }
        }
    }
}

void AVRInteractionManager::ReleaseObject()
{
    if (GrabbedObject)
    {
        GrabbedObject->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
        UPrimitiveComponent* Primitive = Cast<UPrimitiveComponent>(GrabbedObject->GetRootComponent());
        if (Primitive)
        {
            Primitive->SetSimulatePhysics(true);
        }
        GrabbedObject = nullptr;
    }
}
