#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ModdingManager.generated.h"

UCLASS()
class MYGAME_API AModdingManager : public AActor
{
    GENERATED_BODY()

public:
    AModdingManager();

    UFUNCTION(BlueprintCallable, Category = "Modding")
    void LoadModFromPath(FString ModPath);

    UFUNCTION(BlueprintCallable, Category = "Modding")
    UObject* LoadAsset(FString AssetPath);
};
