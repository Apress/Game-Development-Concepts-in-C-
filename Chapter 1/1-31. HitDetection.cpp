#include "HitDetection.h"
#include "Components/SphereComponent.h"

AHitDetection::AHitDetection()
{
    PrimaryActorTick.bCanEverTick = true;

    HitSphere = CreateDefaultSubobject<USphereComponent>(TEXT("HitSphere"));
    RootComponent = HitSphere;

    HitSphere->OnComponentBeginOverlap.AddDynamic(this, &AHitDetection::OnOverlapBegin);
}

void AHitDetection::BeginPlay()
{
    Super::BeginPlay();
}

void AHitDetection::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AHitDetection::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
    // If the hit has already been processed, exit the function
    if (bHasHit)
    {
        return;
    }

    // Process the hit
    // Implement hit processing logic here

    // Set the flag to true to prevent reprocessing the same hit
    bHasHit = true;
}
