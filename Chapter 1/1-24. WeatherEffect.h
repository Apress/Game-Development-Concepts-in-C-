#pragma once

class UParticleSystemComponent;

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeatherEffect.generated.h"

UCLASS()
class MYGAME_API AWeatherEffect : public AActor
{
    GENERATED_BODY()

public:
    AWeatherEffect();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

private:
    // Use EditDefaultsOnly if this property is set in the Blueprint and not at runtime
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weather Effects")

    UParticleSystemComponent* WeatherParticleSystem;
};
