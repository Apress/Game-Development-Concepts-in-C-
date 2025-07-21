#pragma once  

#include "CoreMinimal.h"  
#include "GameFramework/Actor.h"  
#include "LevelManager.generated.h"  

UCLASS()  
class MYGAME_API ALevelManager : public AActor  
{  
    GENERATED_BODY()  

public:  
    ALevelManager();  

    UFUNCTION(BlueprintCallable, Category = "Level")  
    void LoadLevelAssets();  

    UFUNCTION(BlueprintCallable, Category = "Level")  
    void SetGameplayTriggers();  
};  
