#include "AdvancedTrap.h"
#include "Components/BoxComponent.h"

AAdvancedTrap::AAdvancedTrap()
{
    PrimaryActorTick.bCanEverTick = true;

    TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
    RootComponent = TriggerBox;

    TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    TriggerBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
    TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AAdvancedTrap::OnOverlapBegin);

    bIsArmed = true; // Default to armed
}

void AAdvancedTrap::BeginPlay()
{
    Super::BeginPlay();
}

void AAdvancedTrap::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AAdvancedTrap::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
    if (bIsArmed && OtherActor && (OtherActor != this) && OtherComp)
    {
        ActivateTrap();
    }
}

void AAdvancedTrap::ActivateTrap()
{
    // Implement trap activation logic here
    // For example, deal damage to the player or spawn a visual effect

    bIsArmed = false; // Disarm the trap after activation
}

void AAdvancedTrap::ResetTrap()
{
    // Implement trap resetting logic here
    // For example, reset the trap after a certain period

    bIsArmed = true; // Re-arm the trap
}
