#include "TriggerVolume.h"
#include "Components/BoxComponent.h"

ATriggerVolume::ATriggerVolume()
{
    PrimaryActorTick.bCanEverTick = true;

    TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
    RootComponent = TriggerBox;

    TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    TriggerBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);

    TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlapBegin);
    TriggerBox->OnComponentEndOverlap.AddDynamic(this, & ThisClass::OnOverlapEnd);
}

void ATriggerVolume::BeginPlay()
{
    Super::BeginPlay();
}

void ATriggerVolume::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ATriggerVolume::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
    // Implement event logic here (e.g., door opening, trap activation)
}

void ATriggerVolume::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor)
{
    // Implement event reset logic here (if needed)
}
