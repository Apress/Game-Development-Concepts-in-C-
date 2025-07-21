#pragma once
 
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DayNightManager.generated.h"
 
UCLASS()
class MYGAME_API ADayNightManager : public AActor
{
    GENERATED_BODY()
 
public:
    ADayNightManager();
 
protected:
    virtual void BeginPlay() override;
 
public:
    virtual void Tick(float DeltaTime) override;
 
    // Directional light actor reference
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lighting")
    AActor* SunLight;
 
    // Current time in HHMM format (e.g., 0930 = 9:30 AM)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
    int32 CurrentTime = 1200;
 
    // Real seconds that represent one in-game minute
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
    float SecondsPerMinute = 1.0f;
 
private:
    // Tracks real-time progress toward the next in-game minute
    float TimeAccumulator = 0.0f;
 
    void UpdateDayNightCycle();
    void UpdateLighting();
    void UpdateSunPosition();
    void IncrementTime();
    float GetTimeAsFloat() const;
};
