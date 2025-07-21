#pragma once
 
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DynamicMusicManager.generated.h"
 
UENUM(BlueprintType)
enum class ESoundtrackState : uint8
{
    Exploration UMETA(DisplayName = "Exploration"),
    Combat      UMETA(DisplayName = "Combat"),
    Boss        UMETA(DisplayName = "Boss")
};
 
UCLASS()
class MYGAME_API ADynamicMusicManager : public AActor
{
    GENERATED_BODY()
 
public:
    ADynamicMusicManager();
 
protected:
    virtual void BeginPlay() override;
 
public:
    virtual void Tick(float DeltaTime) override;
 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Music")
    USoundBase* ExplorationMusic;
 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Music")
    USoundBase* CombatMusic;
 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Music")
    USoundBase* BossMusic;
 
    UFUNCTION(BlueprintCallable, Category = "Music")
    void ChangeMusicState(ESoundtrackState NewState);
 
private:
    void PlayMusic(USoundBase* NewMusic);
 
    ESoundtrackState CurrentMusicState;
};
