#include "BossFightManager.h"
#include "BossCharacter.h"
#include "Engine/World.h"

// Sets default values
ABossFightManager::ABossFightManager()
{
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABossFightManager::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ABossFightManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Check if the boss has been defeated
    CheckBossDefeat();
}

// Start the boss fight by spawning the boss
 void ABossFightManager::StartBossFight()
{
    FVector SpawnLocation = GetActorLocation();
    FRotator SpawnRotation = FRotator::ZeroRotator;
    FVector SpawnScale = FVector(1.0f); // Default scale
 
    // Create transform and spawn parameters
    FTransform SpawnTransform(SpawnRotation, SpawnLocation, SpawnScale);
    FActorSpawnParameters SpawnParams;
 
    // Spawn the boss character in the world
    CurrentBoss = GetWorld()->SpawnActor<ABossCharacter>(BossCharacterClass, SpawnTransform, SpawnParams);
}

// End the boss fight and provide rewards or progression
void ABossFightManager::EndBossFight()
{
    if (CurrentBoss)
    {
        // Trigger victory animation or rewards
        CurrentBoss->Destroy();
    }
}

// Check if the boss has been defeated
void ABossFightManager::CheckBossDefeat()
{
    if (CurrentBoss && CurrentBoss->GetHealth() <= 0)
    {
        EndBossFight();
    }
}
