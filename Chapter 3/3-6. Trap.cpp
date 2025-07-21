#include "Trap.h"
#include "Components/BoxComponent.h"


ATrap::ATrap()
{
    PrimaryActorTick.bCanEverTick = true;

    TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
    RootComponent = TriggerBox;

    TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    TriggerBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
    TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ATrap::OnOverlapBegin);
}

void ATrap::BeginPlay()
{
    Super::BeginPlay();
}

void ATrap::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ATrap::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
    if (OtherActor && (OtherActor != this) && OtherComp)
    {
        // Implement trap activation logic here
    }
}
