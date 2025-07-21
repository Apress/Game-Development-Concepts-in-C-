#include "SoundTrigger.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"

ASoundTrigger::ASoundTrigger()
{
    PrimaryActorTick.bCanEverTick = false;

    // Create and set up box component
    TriggerZone = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerZone"));
    RootComponent = TriggerZone;
    TriggerZone->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    TriggerZone->SetCollisionObjectType(ECC_WorldDynamic);
    TriggerZone->SetCollisionResponseToAllChannels(ECR_Ignore);
    TriggerZone->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
    TriggerZone->SetBoxExtent(FVector(200.0f));

    TriggerZone->OnComponentBeginOverlap.AddDynamic(this, &ASoundTrigger::OnPlayerEnter);
}

void ASoundTrigger::BeginPlay()
{
    Super::BeginPlay();
}

void ASoundTrigger::PlaySoundAtTrigger()
{
    if (TriggerSound)
    {
        UGameplayStatics::PlaySoundAtLocation(this, TriggerSound, GetActorLocation());
    }
}

void ASoundTrigger::OnPlayerEnter(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndexm, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor && OtherActor == GetWorld()->GetFirstPlayerController()->GetPawn())
    {
        PlaySoundAtTrigger();
    }
}
