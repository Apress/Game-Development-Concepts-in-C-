#pragma once  

#include "CoreMinimal.h"  
#include "GameFramework/Actor.h"  
#include "LagCompensationManager.generated.h"  

UCLASS()  
class MYGAME_API ALagCompensationManager : public AActor  
{  
    GENERATED_BODY()  

public:  
    ALagCompensationManager();  

    UFUNCTION(Server, Reliable, WithValidation)  
    void Server_RegisterHit(FVector HitLocation, float Timestamp);  

protected:  
    virtual void BeginPlay() override;  

private:  
    struct FPlayerSnapshot  
    {  
        FVector Location;  
        FRotator Rotation;  
        float Timestamp;  
    };  

    TArray<FPlayerSnapshot> PlayerSnapshots;  

    void SavePlayerSnapshot();  
    bool ValidateHit(FVector HitLocation, float Timestamp);  
};  
