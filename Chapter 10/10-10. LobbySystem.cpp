#include "LobbySystem.h"  
#include "Net/UnrealNetwork.h"  

ALobbySystem::ALobbySystem()  
{  
    PrimaryActorTick.bCanEverTick = false;  
}  

void ALobbySystem::BeginPlay()  
{  
    Super::BeginPlay();  
}  

void ALobbySystem::AddPlayer(APlayerController* NewPlayer)  
{  
    if (NewPlayer)  
    {  
        ConnectedPlayers.Add(NewPlayer);  
        UE_LOG(LogTemp, Log, TEXT("Player added. Total players: %d"), ConnectedPlayers.Num());  
    }  
}  

void ALobbySystem::RemovePlayer(APlayerController* ExitingPlayer)  
{  
    if (ExitingPlayer)  
    {  
        ConnectedPlayers.Remove(ExitingPlayer);  
        UE_LOG(LogTemp, Log, TEXT("Player removed. Total players: %d"), ConnectedPlayers.Num());  
    }  
}  

bool ALobbySystem::AllPlayersReady() const  
{  
    // Placeholder logic to check if all players are ready.  
    return ConnectedPlayers.Num() >= 2;  
}  

void ALobbySystem::Server_StartMatch_Implementation()  
{  
    if (AllPlayersReady())  
    {  
        UE_LOG(LogTemp, Log, TEXT("All players ready. Starting match!"));  
        // Logic to transition to the game level.  
    }  
    else  
    {  
        UE_LOG(LogTemp, Warning, TEXT("Not all players are ready."));  
    }  
}  

bool ALobbySystem::Server_StartMatch_Validate()  
{  
    return true;  
}  
