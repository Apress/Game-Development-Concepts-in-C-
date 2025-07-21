#pragma once
 
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Camera/CameraShakeBase.h"
#include "CameraShakeComponent.generated.h"
 
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYGAME_API UCameraShakeComponent : public UActorComponent
{
    GENERATED_BODY()
 
public:
    UCameraShakeComponent();
 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shake")
    TSubclassOf<UCameraShakeBase> SprintShake;
 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shake")
    TSubclassOf<UCameraShakeBase> LandingShake;
 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shake")
    float ShakeScale;
 
    UFUNCTION(BlueprintCallable, Category = "Shake")
    void TriggerSprintShake();
 
    UFUNCTION(BlueprintCallable, Category = "Shake")
    void TriggerLandingShake();
};

