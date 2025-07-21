#pragma once  

#include "CoreMinimal.h"  
#include "GameFramework/Actor.h"  
#include "ArenaSetup.generated.h"  

UCLASS()  
class MYGAME_API AArenaSetup : public AActor  
{  
    GENERATED_BODY()  

public:  
    AArenaSetup();  

    UFUNCTION(BlueprintCallable, Category = "Arena")  
    void SetArenaEnvironment();  

private:  
    UPROPERTY(EditAnywhere)  
    TArray<UStaticMeshComponent*> ArenaWalls;  
};  
