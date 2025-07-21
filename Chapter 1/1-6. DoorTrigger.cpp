#include "DoorTrigger.h"
#include "Engine/TriggerVolume.h"
#include "Components/BoxComponent.h"


ADoorTrigger::ADoorTrigger()
{
    PrimaryActorTick.bCanEverTick = true;

    DoorTrigger = CreateDefaultSubobject<ATriggerVolume>(TEXT("DoorTrigger"));
    RootComponent = DoorTrigger;

    DoorTrigger->OnActorBeginOverlap.AddDynamic(this, &ADoorTrigger::OnOverlapBegin);
    DoorTrigger->OnActorEndOverlap.AddDynamic(this, &ADoorTrigger::OnOverlapEnd);
}

void ADoorTrigger::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
    // Implement door opening logic here
}

void ADoorTrigger::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor)
{
    // Implement door closing logic here
}
