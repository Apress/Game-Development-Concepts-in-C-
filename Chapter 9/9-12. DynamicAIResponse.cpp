#include "DynamicAIResponse.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "AIController.h"

ADynamicAIResponse::ADynamicAIResponse()
{
    PrimaryActorTick.bCanEverTick = false;

    DetectionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("DetectionSphere"));
    DetectionSphere->InitSphereRadius(500.0f);
    DetectionSphere->SetupAttachment(RootComponent);

    DetectionSphere->OnComponentBeginOverlap.AddDynamic(this, &ADynamicAIResponse::OnPlayerEnterDetectionSphere);
    DetectionSphere->OnComponentEndOverlap.AddDynamic(this, &ADynamicAIResponse::OnPlayerExitDetectionSphere);

    bPlayerDetected = false;
    bIsUnderThreat = false;
}

void ADynamicAIResponse::BeginPlay()
{
    Super::BeginPlay();
}

void ADynamicAIResponse::OnPlayerEnterDetectionSphere(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                                      UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
                                                      bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor && OtherActor == UGameplayStatics::GetPlayerPawn(GetWorld(), 0))
    {
        bPlayerDetected = true;
        LastKnownPlayerLocation = OtherActor->GetActorLocation();
        ReactToThreat();
    }
}

void ADynamicAIResponse::OnPlayerExitDetectionSphere(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                                     UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (OtherActor && OtherActor == UGameplayStatics::GetPlayerPawn(GetWorld(), 0))
    {
        ReturnToNormalState();
    }
}

void ADynamicAIResponse::ReactToThreat()
{
    if (bPlayerDetected)
    {
        AActor* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
        if (Player && FVector::Dist(GetActorLocation(), Player->GetActorLocation()) < 200.0f)
        {
            bIsUnderThreat = true;
            // Switch to aggressive behavior (e.g., attack or take cover)
        }
    }
}

void ADynamicAIResponse::ReturnToNormalState()
{
    bPlayerDetected = false;
    bIsUnderThreat = false;
    // Reset to idle behavior
}
