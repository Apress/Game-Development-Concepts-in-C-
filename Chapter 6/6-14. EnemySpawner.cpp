#include "EnemySpawner.h"
#include "Enemy.h"
#include "Engine/World.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
    PrimaryActorTick.bCanEverTick = true;
    SpawnInterval = 5.0f; // Default spawn interval of 5 seconds
    ElapsedTime = 0.0f;
}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    ElapsedTime += DeltaTime;

    // Check if it's time to spawn an enemy
    if (ElapsedTime >= SpawnInterval)
    {
        SpawnEnemy();
        ElapsedTime = 0.0f; // Reset the timer
    }
}

// Spawns an enemy at a random location
 void AEnemySpawner::SpawnEnemy()
{
    FVector SpawnLocation = GetRandomSpawnLocation();
    FRotator SpawnRotation = FRotator::ZeroRotator;
    FVector SpawnScale = FVector(1.0f); // Default scale
 
    // Create transform and spawn parameters
    FTransform SpawnTransform(SpawnRotation, SpawnLocation, SpawnScale);
    FActorSpawnParameters SpawnParams;
 
    // Spawn the enemy actor in the world
    GetWorld()->SpawnActor<AEnemy>(EnemyClass, SpawnTransform, SpawnParams);
}

// Get a random location for spawning an enemy
FVector AEnemySpawner::GetRandomSpawnLocation()
{
    // For example, spawn within a certain range around the spawner's location
    FVector Origin = GetActorLocation();
    float XOffset = FMath::RandRange(-500.f, 500.f);
    float YOffset = FMath::RandRange(-500.f, 500.f);
    return FVector(Origin.X + XOffset, Origin.Y + YOffset, Origin.Z);
}
