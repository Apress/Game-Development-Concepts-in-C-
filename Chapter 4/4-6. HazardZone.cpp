#include "HazardZone.h"
#include "MyPlayerCharacter.h"
#include "Components/BoxComponent.h"

// Constructor: Sets default values
AHazardZone::AHazardZone()
{
    PrimaryActorTick.bCanEverTick = true;

    DamagePerSecond = 10.0f;
    bIsActive = true;

    // Create and set up the collision component
    TriggerZone = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerZone"));
    RootComponent = TriggerZone;

    TriggerZone->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    TriggerZone->SetCollisionObjectType(ECC_WorldDynamic);
    TriggerZone->SetCollisionResponseToAllChannels(ECR_Ignore);
    TriggerZone->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
    TriggerZone->SetGenerateOverlapEvents(true);

    // Bind overlap events
    TriggerZone->OnComponentBeginOverlap.AddDynamic(this, &AHazardZone::OnPlayerEnter);
    TriggerZone->OnComponentEndOverlap.AddDynamic(this, &AHazardZone::OnPlayerExit);

    PlayerCharacter = nullptr;
}

// BeginPlay: Called when the game starts
void AHazardZone::BeginPlay()
{
    Super::BeginPlay();
}

// Tick: Called every frame
void AHazardZone::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bIsActive && PlayerCharacter)
    {
        PlayerCharacter->TakeDamage(DamagePerSecond * DeltaTime);
    }
}

// OnPlayerEnter: Called when a player enters the hazard zone
void AHazardZone::OnPlayerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor && OtherActor->IsA(AMyPlayerCharacter::StaticClass()))
    {
        PlayerCharacter = Cast<AMyPlayerCharacter>(OtherActor);
    }
}

// OnPlayerExit: Called when a player exits the hazard zone
void AHazardZone::OnPlayerExit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (OtherActor == PlayerCharacter)
    {
        PlayerCharacter = nullptr;
    }
}
