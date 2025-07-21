#include "PlayerCharacter.h"
#include "Components/CapsuleComponent.h"

APlayerCharacter::APlayerCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    PlayerCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("PlayerCapsule"));
    RootComponent = PlayerCapsule;

    PlayerCapsule->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    PlayerCapsule->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
}

void APlayerCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void APlayerCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
