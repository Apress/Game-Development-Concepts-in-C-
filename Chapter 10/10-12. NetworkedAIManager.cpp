#include "NetworkedAIManager.h"  
#include "Net/UnrealNetwork.h"  

ANetworkedAIManager::ANetworkedAIManager()  
{  
    PrimaryActorTick.bCanEverTick = false;  
    bReplicates = true;  
}  

void ANetworkedAIManager::BeginPlay()  
{  
    Super::BeginPlay();  
}  

void ANetworkedAIManager::Server_MoveAI_Implementation(FVector NewLocation)  
{  
    AIActorLocation = NewLocation;  
    OnRep_AIActorLocation();  
}  

bool ANetworkedAIManager::Server_MoveAI_Validate(FVector NewLocation)  
{  
    return true;  
}  

void ANetworkedAIManager::OnRep_AIActorLocation()
{
    AAIController* AIController = Cast<AAIController>(GetController());
    if (AIController)
    {
        AIController->MoveToLocation(AIActorLocation, -1.0f, true, true, true, false, 0, true);
    }
}

void ANetworkedAIManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const  
{  
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);  
    DOREPLIFETIME(ANetworkedAIManager, AIActorLocation);  
}  

