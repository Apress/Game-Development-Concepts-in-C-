#pragma once  

#include "CoreMinimal.h"  
#include "GameFramework/Actor.h"  
#include "MatchmakingManager.generated.h"  

UCLASS()  
class MYGAME_API AMatchmakingManager : public AActor  
{  
    GENERATED_BODY()  

public:  
    AMatchmakingManager();  

    UFUNCTION(BlueprintCallable, Category = "Matchmaking")  
    void AddPlayerToQueue(APlayerController* Player);  

    UFUNCTION(BlueprintCallable, Category = "Matchmaking")  
    void StartMatchIfReady();  

protected:  
    virtual void BeginPlay() override;  

private:  
    TArray<APlayerController*> PlayerQueue;  
    int32 PlayersPerMatch = 4;  
};  
