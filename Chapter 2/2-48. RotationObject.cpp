#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "RotationObject.h"


ARotationObject::ARotationObject()
{
    PrimaryActorTick.bCanEverTick = true;

    ObjectMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ObjectMesh"));
    RootComponent = ObjectMesh;

    CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
    CollisionSphere->SetupAttachment(RootComponent);

    MaxRotationAngle = 90.0f;
    CollisionThreshold = 500.0f;
    bIsRotationEnabled = true;

    CollisionSphere->OnComponentHit.AddDynamic(this, &ARotationObject::OnObjectCollision);
}


void ARotationObject::OnObjectCollision(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    if (!bIsRotationEnabled)
        return;

    float ImpulseMagnitude = NormalImpulse.Size();
    if (ImpulseMagnitude > CollisionThreshold)
    {
        RotateObject(ImpulseMagnitude);
    }
}

void ARotationObject::RotateObject(float ImpulseMagnitude)
{
    float RotationAngle = FMath::Lerp(0.0f, MaxRotationAngle, ImpulseMagnitude / CollisionThreshold);

    // Determine dynamic rotation axis
    float Yaw = FMath::RandBool() ? RotationAngle : 0.0f;
    float Pitch = FMath::RandBool() ? RotationAngle : 0.0f;
    float Roll = FMath::RandBool() ? RotationAngle : 0.0f;

    FRotator RotationDelta = FRotator(Pitch, Yaw, Roll);
    ObjectMesh->AddLocalRotation(RotationDelta);

    // Add visual feedback or animation here
}
