#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BossFightManager.generated.h"

// Forward declaration of ABossCharacter
class ABossCharacter;

UCLASS()
class YOURGAME_API ABossFightManager : public AActor
{
    GENERATED_BODY()

public:
    ABossFightManager();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    // Reference to the boss character
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boss Fight")
    TSubclassOf<ABossCharacter> BossCharacterClass;

    // The current boss in the fight
    ABossCharacter* CurrentBoss;

    // Method to start the boss fight
    void StartBossFight();

    // Method to end the boss fight
    void EndBossFight();

private:
    // Check if the boss has been defeated
    void CheckBossDefeat();
};
