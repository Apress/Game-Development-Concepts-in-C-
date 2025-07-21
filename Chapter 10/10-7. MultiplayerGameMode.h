#pragma once  

#include "CoreMinimal.h"  
#include "GameFramework/GameModeBase.h"  
#include "MultiplayerGameMode.generated.h"  

UCLASS()  
class MYGAME_API AMultiplayerGameMode : public AGameModeBase  
{  
    GENERATED_BODY()  

public:  
    AMultiplayerGameMode();  

    UFUNCTION(BlueprintCallable, Category = "GameMode")  
    void AssignTeams();  

    UFUNCTION(Server, Reliable, WithValidation)  
    void Server_EndMatch(bool bTeamOneWins);  

protected:  
    virtual void BeginPlay() override;  

private:  
    TArray<APlayerController*> TeamOnePlayers;  
    TArray<APlayerController*> TeamTwoPlayers;  
};  
