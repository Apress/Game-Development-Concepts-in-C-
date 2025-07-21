#include "Door.h"
#include "Components/BoxComponent.h"

ADoor::ADoor()
{
    PrimaryActorTick.bCanEverTick = true;

    TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
    RootComponent = TriggerBox;

    TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    TriggerBox >SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
    TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ADoor::OnOverlapBegin);

    bIsLocked = false; // Default to unlocked
}

void ADoor::BeginPlay()
{
    Super::BeginPlay();
}

void ADoor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ADoor:: OnBeginOverlap (UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
    if (!bIsLocked)
    {
        // Implement door opening logic here
    }
}
