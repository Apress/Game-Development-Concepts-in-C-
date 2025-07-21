#include "ChatManager.h"  
#include "GameFramework/PlayerState.h"  

AChatManager::AChatManager()  
{  
    PrimaryActorTick.bCanEverTick = false;  
}  

void AChatManager::BeginPlay()  
{  
    Super::BeginPlay();  
}  

void AChatManager::SendMessageToAll(const FString& Message, APlayerController* Sender)  
{  
    if (Sender)  
    {  
        FString SenderName = Sender->PlayerState->GetPlayerName();  
        FString FullMessage = FString::Printf(TEXT("%s: %s"), *SenderName, *Message);  

        // Broadcast the message to all players  
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FullMessage);  
    }  
}  

void AChatManager::SendMessageToTeam(const FString& Message, APlayerController* Sender)  
{  
    if (Sender)  
    {  
        FString SenderName = Sender->PlayerState->GetPlayerName();  
        FString FullMessage = FString::Printf(TEXT("%s (Team): %s"), *SenderName, *Message);  

        // Logic to send message to team members only  
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FullMessage);  
    }  
}  
