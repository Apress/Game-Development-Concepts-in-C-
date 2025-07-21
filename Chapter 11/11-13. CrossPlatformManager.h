#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CrossPlatformManager.generated.h"

UCLASS()
class MYGAME_API ACrossPlatformManager : public AActor
{
    GENERATED_BODY()

public:
    ACrossPlatformManager();

    UFUNCTION(BlueprintCallable, Category = "Cross-Platform")
    void DetectPlatform();

    UFUNCTION(BlueprintCallable, Category = "Cross-Platform")
    void ConfigureInputSettings();
};
