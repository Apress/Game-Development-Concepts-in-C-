#pragma once  

#include "CoreMinimal.h"  
#include "GameFramework/GameModeBase.h"  
#include "LobbySystem.generated.h"  

UCLASS()  
class MYGAME_API ALobbySystem : public AGameModeBase  
{  
    GENERATED_BODY()  

public:  
    ALobbySystem();  

    UFUNCTION(BlueprintCallable, Category = "Lobby")  
    void AddPlayer(APlayerController* NewPlayer);  

    UFUNCTION(BlueprintCallable, Category = "Lobby")  
    void RemovePlayer(APlayerController* ExitingPlayer);  

    UFUNCTION(Server, Reliable, WithValidation)  
    void Server_StartMatch();  

protected:  
    virtual void BeginPlay() override;  

private:  
    TArray<APlayerController*> ConnectedPlayers;  
    bool AllPlayersReady() const;  
};  
