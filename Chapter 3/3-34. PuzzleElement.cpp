#include "PuzzleElement.h"
#include "Components/StaticMeshComponent.h"


APuzzleElement::APuzzleElement()
{
    PrimaryActorTick.bCanEverTick = true;

    PuzzleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PuzzleMesh"));
    RootComponent = PuzzleMesh;

    PuzzleMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    PuzzleMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
}

void APuzzleElement::BeginPlay()
{
    Super::BeginPlay();
}

void APuzzleElement::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void APuzzleElement::OnInteract()
{
    // Implement puzzle interaction logic here
}
