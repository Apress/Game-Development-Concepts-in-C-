#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PostProcessingManager.generated.h"

UCLASS()
class MYGAME_API APostProcessingManager : public AActor
{
    GENERATED_BODY()

public:
    APostProcessingManager();

protected:
    virtual void BeginPlay() override;

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Post Processing")
    class UPostProcessComponent* PostProcessComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Post Processing Settings")
    float BloomIntensity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Post Processing Settings")
    FVector4 ColorGrading;

    UFUNCTION(BlueprintCallable, Category = "Post Processing")
    void UpdatePostProcessing(float NewBloomIntensity, FVector4 NewColorGrading);
};
