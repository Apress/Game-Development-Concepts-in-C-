#pragma once  

#include "CoreMinimal.h"  
#include "GameFramework/Actor.h"  
#include "ServerAuthoritativeMovement.generated.h"  

UCLASS()  
class MYGAME_API AServerAuthoritativeMovement : public AActor  
{  
    GENERATED_BODY()  

public:  
    AServerAuthoritativeMovement();  

    UFUNCTION(Server, Reliable, WithValidation)  
    void Server_MovePlayer(FVector NewLocation);  

protected:  
    virtual void BeginPlay() override;  
};  
