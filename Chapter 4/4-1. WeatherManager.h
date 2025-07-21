#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeatherManager.generated.h"

UENUM(BlueprintType)
enum class EWeatherState : uint8
{
    Sunny UMETA(DisplayName = "Sunny"),
    Rainy UMETA(DisplayName = "Rainy"),
    Foggy UMETA(DisplayName = "Foggy"),
    Stormy UMETA(DisplayName = "Stormy"),
};

UCLASS()
class MYGAME_API AWeatherManager : public AActor
{
    GENERATED_BODY()

public:
    AWeatherManager();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weather")
    EWeatherState CurrentWeatherState;

    UFUNCTION(BlueprintCallable, Category = "Weather")
    void SetWeatherState(EWeatherState NewState);

    UFUNCTION(BlueprintCallable, Category = "Weather")
    void UpdateWeatherEffects();

private:
    void ChangeWeatherToSunny();
    void ChangeWeatherToRainy();
    void ChangeWeatherToFoggy();
    void ChangeWeatherToStormy();
    void ApplyWeatherSettings(float LightIntensity, bool bEnableRain, bool bEnableFog);

};
