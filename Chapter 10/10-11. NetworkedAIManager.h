#pragma once  

#include "CoreMinimal.h"  
#include "GameFramework/Actor.h"  
#include "NetworkedAIManager.generated.h"  

UCLASS()  
class MYGAME_API ANetworkedAIManager : public AActor  
{  
    GENERATED_BODY()  

public:  
    ANetworkedAIManager();  

    UFUNCTION(Server, Reliable, WithValidation)  
    void Server_MoveAI(FVector NewLocation);  

protected:  
    virtual void BeginPlay() override;  

private:  
    UPROPERTY(Replicated)  
    FVector AIActorLocation;  

    UFUNCTION()  
    void OnRep_AIActorLocation();  
};  
