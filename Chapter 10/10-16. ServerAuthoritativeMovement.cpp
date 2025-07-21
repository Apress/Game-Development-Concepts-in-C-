#include "ServerAuthoritativeMovement.h"  

AServerAuthoritativeMovement::AServerAuthoritativeMovement()  
{  
    PrimaryActorTick.bCanEverTick = false;  
}  

void AServerAuthoritativeMovement::BeginPlay()  
{  
    Super::BeginPlay();  
}  

void AServerAuthoritativeMovement::Server_MovePlayer_Implementation(FVector NewLocation)  
{  
    if (HasAuthority())  
    {  
        SetActorLocation(NewLocation);  
        UE_LOG(LogTemp, Log, TEXT("Player moved to: %s"), *NewLocation.ToString());  
    }  
}  

bool AServerAuthoritativeMovement::Server_MovePlayer_Validate(FVector NewLocation)  
{  
    // Add validation logic here, e.g., ensuring movement is within allowed bounds  
    return true;  
}  
