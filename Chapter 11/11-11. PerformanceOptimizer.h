#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PerformanceOptimizer.generated.h"

UCLASS()
class MYGAME_API APerformanceOptimizer : public AActor
{
    GENERATED_BODY()

public:
    APerformanceOptimizer();

    UFUNCTION(BlueprintCallable, Category = "Performance")
    void EnableFramerateSmoothing();

    UFUNCTION(BlueprintCallable, Category = "Performance")
    void OptimizeTextureSettings();

protected:
    virtual void BeginPlay() override;
};
