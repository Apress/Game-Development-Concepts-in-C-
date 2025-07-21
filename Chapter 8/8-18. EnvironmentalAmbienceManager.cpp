#include "EnvironmentalAmbienceManager.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundCue.h"
#include "Kismet/GameplayStatics.h"

AEnvironmentalAmbienceManager::AEnvironmentalAmbienceManager()
{
    PrimaryActorTick.bCanEverTick = false;
    ActiveAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("ActiveAudioComponent"));
    ActiveAudioComponent->bAutoActivate = false;
}

void AEnvironmentalAmbienceManager::BeginPlay()
{
    Super::BeginPlay();
    if (DefaultAmbience)
    {
        PlayAmbience(DefaultAmbience);
    }
}

void AEnvironmentalAmbienceManager::PlayAmbience(USoundCue* AmbienceCue)
{
    if (ActiveAudioComponent && AmbienceCue)
    {
        ActiveAudioComponent->SetSound(AmbienceCue);
        ActiveAudioComponent->Play();
    }
}

void AEnvironmentalAmbienceManager::StopAmbience()
{
    if (ActiveAudioComponent)
    {
        ActiveAudioComponent->Stop();
    }
}

