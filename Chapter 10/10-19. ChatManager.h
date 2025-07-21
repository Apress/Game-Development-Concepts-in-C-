#pragma once  

#include "CoreMinimal.h"  
#include "GameFramework/Actor.h"  
#include "ChatManager.generated.h"  

UCLASS()  
class MYGAME_API AChatManager : public AActor  
{  
    GENERATED_BODY()  

public:  
    AChatManager();  

    UFUNCTION(BlueprintCallable, Category = "Chat")  
    void SendMessageToAll(const FString& Message, APlayerController* Sender);  

    UFUNCTION(BlueprintCallable, Category = "Chat")  
    void SendMessageToTeam(const FString& Message, APlayerController* Sender);  

protected:  
    virtual void BeginPlay() override;  
};  
