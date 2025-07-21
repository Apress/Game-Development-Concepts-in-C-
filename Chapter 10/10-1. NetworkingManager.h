#pragma once  

#include "CoreMinimal.h"  
#include "GameFramework/Actor.h"  
#include "NetworkingManager.generated.h"  

UCLASS()  
class MYGAME_API ANetworkingManager : public AActor  
{  
    GENERATED_BODY()  

public:  
    ANetworkingManager();  

protected:  
    virtual void BeginPlay() override;  

public:  
    virtual void Tick(float DeltaTime) override;  

    UFUNCTION(BlueprintCallable, Category = "Networking")  
    void EstablishConnection();  
};  
