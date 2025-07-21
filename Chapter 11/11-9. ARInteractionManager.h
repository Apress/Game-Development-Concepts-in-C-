#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ARBlueprintLibrary.h"
#include "ARInteractionManager.generated.h"

UCLASS()
class MYGAME_API AARInteractionManager : public AActor
{
    GENERATED_BODY()

public:
    AARInteractionManager();

    UFUNCTION(BlueprintCallable, Category = "AR")
    void SpawnARObject(FVector Location);

    UFUNCTION(BlueprintCallable, Category = "AR")
    void DetectARPlanes();

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY()
    TArray<UARPlaneGeometry*> DetectedPlanes;

    UPROPERTY(EditAnywhere, Category = "AR")
    TSubclassOf<AActor> ARObjectClass;
};
