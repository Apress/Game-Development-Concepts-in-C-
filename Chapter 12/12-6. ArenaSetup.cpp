#include "ArenaSetup.h"  

AArenaSetup::AArenaSetup()  
{  
    PrimaryActorTick.bCanEverTick = false;  
}  

void AArenaSetup::SetArenaEnvironment()  
{  
    // Setup arena walls and environment details  
    for (UStaticMeshComponent* Wall : ArenaWalls)  
    {  
        Wall->SetVisibility(true);  
    }  
}  
