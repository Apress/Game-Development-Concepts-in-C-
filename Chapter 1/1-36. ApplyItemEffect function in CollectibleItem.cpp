ACollectibleItem::ACollectibleItem()
{
    PrimaryActorTick.bCanEverTick = true;

    // Initialize collision component

    CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));

    RootComponent = CollisionSphere;

    CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &ACollectibleItem::OnOverlapBegin);

    // Bind sound and particle system assets through ConstructorHelpers
    static ConstructorHelpers::FObjectFinder<USoundBase> SoundAsset(TEXT("SoundWave'/Game/Audio/CollectSound.CollectSound'"));
    if (SoundAsset.Succeeded())
    {
        CollectSound = SoundAsset.Object;
    }

    static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("ParticleSystem'/Game/Particles/CollectEffect.CollectEffect'"));
    if (ParticleAsset.Succeeded())
    {
        CollectParticleEffect = ParticleAsset.Object;
    }
}

void ACollectibleItem::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
                                      bool bFromSweep, const FHitResult & SweepResult)
{
    if (OtherActor && (OtherActor != this))
    {
        // Increase the count when an item is collected
        CollectedItemCount++;

        // Optionally, print the count for debugging
        UE_LOG(LogTemp, Log, TEXT("Items Collected: %d"), CollectedItemCount);

        // Play sound effect on collection
        if (CollectSound)
        {
            UGameplayStatics::PlaySoundAtLocation(this, CollectSound, GetActorLocation());
        }

        // Play particle effect on collection
        if (CollectParticleEffect)
        {
            UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), CollectParticleEffect, GetActorLocation());
        }

        // Implement item collection logic here
        Destroy();
    }
}
