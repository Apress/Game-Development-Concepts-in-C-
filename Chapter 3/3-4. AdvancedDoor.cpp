#include "AdvancedDoor.h"
#include "Components/BoxComponent.h"

AAdvancedDoor::AAdvancedDoor()
{
    PrimaryActorTick.bCanEverTick = true;

    TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
    RootComponent = TriggerBox;

    TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    TriggerBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
    TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AAdvancedDoor::OnOverlapBegin);

    bIsLocked = true; // Default to locked
}

void AAdvancedDoor::BeginPlay()
{
    Super::BeginPlay();
}

void AAdvancedDoor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AAdvancedDoor::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
    if (!bIsLocked || HasKey(OtherActor))
    {
        // Implement door opening logic here
    }
}

bool AAdvancedDoor::HasKey(AActor* OtherActor)
{
    // Check if the player has the required key
    // This is a placeholder function and should be implemented based on the game's inventory system
    return true;
}
