#include "CollectibleItem.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"


ACollectibleItem::ACollectibleItem()
{
    PrimaryActorTick.bCanEverTick = true;

    CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
    RootComponent = CollisionSphere;

    CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &ACollectibleItem::OnOverlapBegin);
}

void ACollectibleItem::BeginPlay()
{
    Super::BeginPlay();
}

void ACollectibleItem::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// In CollectibleItem.h
private:
    static int32 CollectedItemCount; // Static counter to track total collected items

// In CollectibleItem.cpp
int32 ACollectibleItem::CollectedItemCount = 0; // Initialize static variable

void ACollectibleItem::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
bool bFromSweep, const FHitResult & SweepResult)
{
    if (OtherActor && (OtherActor != this))
    {
        // Increase the count when an item is collected
        CollectedItemCount++;

        // Optionally, print the count for debugging
        UE_LOG(LogTemp, Log, TEXT("Items Collected: %d"), CollectedItemCount);

        // Implement item collection logic here
        Destroy();
    }
}
