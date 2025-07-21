#include "MazeWall.h"
#include "Components/StaticMeshComponent.h"

AMazeWall::AMazeWall()
{
    PrimaryActorTick.bCanEverTick = true;

    MazeWall = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MazeWall"));
    RootComponent = MazeWall;

    MazeWall->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    MazeWall->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
}

void AMazeWall::BeginPlay()
{
    Super::BeginPlay();
}

void AMazeWall::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
