#include "StealthEnemyAI.h"
#include "Kismet/GameplayStatics.h"

AStealthEnemyAI::AStealthEnemyAI()
{
    PrimaryActorTick.bCanEverTick = true;
    bPlayerDetected = false;
}
#include "StealthEnemyAI.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h"

AStealthEnemyAI::AStealthEnemyAI()
{
    PrimaryActorTick.bCanEverTick = false;

    bPlayerDetected = false;

    DetectionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("DetectionSphere"));
    DetectionSphere->InitSphereRadius(300.0f);
    DetectionSphere->SetupAttachment(RootComponent);
    DetectionSphere->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
    DetectionSphere->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
}

void AStealthEnemyAI::BeginPlay()
{
    Super::BeginPlay();
    DetectionSphere->OnComponentBeginOverlap.AddDynamic(this, &AStealthEnemyAI::OnPlayerEnterRange);
}

void AStealthEnemyAI::OnPlayerEnterRange(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                         UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
                                         bool bFromSweep, const FHitResult& SweepResult)
{
    if (!bPlayerDetected && OtherActor == UGameplayStatics::GetPlayerPawn(GetWorld(), 0))
    {
        bPlayerDetected = true;
        LastKnownPlayerLocation = OtherActor->GetActorLocation();
        SearchForPlayer();
    }
}

void AStealthEnemyAI::SearchForPlayer()
{
    if (bPlayerDetected)
    {
        AAIController* AIController = Cast<AAIController>(GetController());
        if (AIController)
        {
            AIController->MoveToLocation(LastKnownPlayerLocation);
        }
    }
}

void AStealthEnemyAI::ReturnToPatrol()
{
    bPlayerDetected = false;
    // Add logic for returning to patrol path
}
void AStealthEnemyAI::BeginPlay()
{
    Super::BeginPlay();
}

void AStealthEnemyAI::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!bPlayerDetected)
    {
        DetectPlayer();
    }
}

void AStealthEnemyAI::DetectPlayer()
{
    AActor* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (Player && FVector::Dist(GetActorLocation(), Player->GetActorLocation()) < 300.0f)
    {
        bPlayerDetected = true;
        LastKnownPlayerLocation = Player->GetActorLocation();
        SearchForPlayer();
    }
} 

void AStealthEnemyAI::SearchForPlayer()
{
    if (bPlayerDetected)
    {
        MoveToLocation(LastKnownPlayerLocation);
        // Add search logic like scanning the area
    }
}

void AStealthEnemyAI::ReturnToPatrol()
{
    bPlayerDetected = false;
    // Add logic to return to the patrol path
