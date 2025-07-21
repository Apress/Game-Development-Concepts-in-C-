#include "MatchmakingManager.h"  

AMatchmakingManager::AMatchmakingManager()  
{  
    PrimaryActorTick.bCanEverTick = false;  
}  

void AMatchmakingManager::BeginPlay()  
{  
    Super::BeginPlay();  
}  

void AMatchmakingManager::AddPlayerToQueue(APlayerController* Player)  
{  
    if (Player)  
    {  
        PlayerQueue.Add(Player);  
        UE_LOG(LogTemp, Log, TEXT("Player added to matchmaking queue. Total: %d"), PlayerQueue.Num());  

        StartMatchIfReady();  
    }  
}  

void AMatchmakingManager::StartMatchIfReady()  
{  
    if (PlayerQueue.Num() >= PlayersPerMatch)  
    {  
        UE_LOG(LogTemp, Log, TEXT("Match is ready to start!"));  

        // Logic to group players into a match and start the game  
        PlayerQueue.Empty();  
    }  
}  
