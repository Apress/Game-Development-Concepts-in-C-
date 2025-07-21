#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MotionControllerComponent.h"
#include "VRInteractionManager.generated.h"

UCLASS()
class MYGAME_API AVRInteractionManager : public AActor
{
    GENERATED_BODY()

public:
    AVRInteractionManager();

    UFUNCTION(BlueprintCallable, Category = "VR")
    void GrabObject();

    UFUNCTION(BlueprintCallable, Category = "VR")
    void ReleaseObject();

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY()
    UMotionControllerComponent* MotionController;

    UPROPERTY()
    AActor* GrabbedObject;
};
