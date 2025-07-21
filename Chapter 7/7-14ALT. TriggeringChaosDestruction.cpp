#include "GeometryCollectionActor.h"
#include "GeometryCollectionComponent.h"
 
void AMyActor::ApplyDamageToGeometry()
{
    AGeometryCollectionActor* DestructibleActor = Cast<AGeometryCollectionActor>(TargetActor);
    if (DestructibleActor && DestructibleActor->GetGeometryCollectionComponent())
    {
        DestructibleActor->GetGeometryCollectionComponent()->ApplyDamage(
            100.0f,                             // Damage amount
            HitLocation,                        // Location of impact
            FVector::UpVector * 500.0f,         // Impulse direction/strength
            1000.0f                             // Radius
        );
    }
}
