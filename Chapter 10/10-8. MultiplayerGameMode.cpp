#include "MultiplayerGameMode.h"  
#include "GameFramework/PlayerController.h"  
#include "Net/UnrealNetwork.h"  

AMultiplayerGameMode::AMultiplayerGameMode()  
{  
    PrimaryActorTick.bCanEverTick = false;  
}  

void AMultiplayerGameMode::BeginPlay()  
{  
    Super::BeginPlay();  
    AssignTeams();  
}  

void AMultiplayerGameMode::AssignTeams()  
{  
    TArray<APlayerController*> AllPlayers;  
    GetWorld()->GetPlayerControllerIterator().GetAll(AllPlayers);  

    for (int32 i = 0; i < AllPlayers.Num(); ++i)  
    {  
        if (i % 2 == 0)  
        {  
            TeamOnePlayers.Add(AllPlayers[i]);  
        }  
        else  
        {  
            TeamTwoPlayers.Add(AllPlayers[i]);  
        }  
    }  
}  

void AMultiplayerGameMode::Server_EndMatch_Implementation(bool bTeamOneWins)  
{  
    FString Winner = bTeamOneWins ? TEXT("Team One") : TEXT("Team Two");  
    UE_LOG(LogTemp, Log, TEXT("%s wins the match!"), *Winner);  
}  

bool AMultiplayerGameMode::Server_EndMatch_Validate(bool bTeamOneWins)  
{  
    return true;  
}  
