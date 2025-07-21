#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

// Forward declaration of AEnemy class
class AEnemy;

UCLASS()
class YOURGAME_API AEnemySpawner : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AEnemySpawner();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Time interval between enemy spawns
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
    float SpawnInterval;

    // Timer to track time between spawns
    float ElapsedTime;

    // Reference to the Enemy class
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
    TSubclassOf<AEnemy> EnemyClass;

    // Method to spawn an enemy at a random location
    void SpawnEnemy();
    
private:
    // Get a random spawn location within the bounds
    FVector GetRandomSpawnLocation();
};
