#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "ScalingObject.h"


AScalingObject::AScalingObject()
{
    PrimaryActorTick.bCanEverTick = true;

    ObjectMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ObjectMesh"));
    RootComponent = ObjectMesh;

    CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
    CollisionSphere->SetupAttachment(RootComponent);

    MinScale = 0.5f;
    MaxScale = 2.0f;
    CollisionThreshold = 500.0f;
    bIsScalingEnabled = true;

    CollisionSphere->OnComponentHit.AddDynamic(this, &AScalingObject::OnObjectCollision);
}

void AScalingObject::OnObjectCollision(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    if (!bIsScalingEnabled)
        return;

    float ImpulseMagnitude = NormalImpulse.Size();
    if (ImpulseMagnitude > CollisionThreshold)
    {
        ScaleObject(ImpulseMagnitude);
    }
}

void AScalingObject::ScaleObject(float ImpulseMagnitude)
{
    float ScaleFactor = FMath::Lerp(MinScale, MaxScale, ImpulseMagnitude / CollisionThreshold);
    FVector NewScale = FVector(ScaleFactor);

    ObjectMesh->SetWorldScale3D(NewScale);

    // Add visual feedback or animation here
}
