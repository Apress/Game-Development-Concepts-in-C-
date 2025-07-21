#include "LagCompensationManager.h"  
#include "GameFramework/PlayerController.h"  

ALagCompensationManager::ALagCompensationManager()  
{  
    PrimaryActorTick.bCanEverTick = true;  
}  

void ALagCompensationManager::BeginPlay()  
{  
    Super::BeginPlay();  
}  

void ALagCompensationManager::SavePlayerSnapshot()  
{  
    FPlayerSnapshot Snapshot;  
    Snapshot.Location = GetActorLocation();  
    Snapshot.Rotation = GetActorRotation();  
    Snapshot.Timestamp = GetWorld()->GetTimeSeconds();  

    PlayerSnapshots.Add(Snapshot);  

    // Remove old snapshots to optimize performance  
    while (PlayerSnapshots.Num() > 50)  
    {  
        PlayerSnapshots.RemoveAt(0);  
    }  
}  

bool ALagCompensationManager::ValidateHit(FVector HitLocation, float Timestamp)  
{  
    for (const FPlayerSnapshot& Snapshot : PlayerSnapshots)  
    {  
        if (FMath::Abs(Snapshot.Timestamp - Timestamp) < 0.05f)  
        {  
            if (FVector::Dist(Snapshot.Location, HitLocation) < 50.0f)  
            {  
                return true;  
            }  
        }  
    }  
    return false;  
}  

void ALagCompensationManager::Server_RegisterHit_Implementation(FVector HitLocation, float Timestamp)  
{  
    if (ValidateHit(HitLocation, Timestamp))  
    {  
        UE_LOG(LogTemp, Log, TEXT("Hit validated!"));  
    }  
    else  
    {  
        UE_LOG(LogTemp, Warning, TEXT("Hit rejected due to lag mismatch."));  
    }  
}  

bool ALagCompensationManager::Server_RegisterHit_Validate(FVector HitLocation, float Timestamp)  
{  
    return true;  
}  
