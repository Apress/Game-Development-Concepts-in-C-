#include "PlayerSyncComponent.h"  
#include "Net/UnrealNetwork.h"  

UPlayerSyncComponent::UPlayerSyncComponent()  
{  
    PrimaryComponentTick.bCanEverTick = true;  
    SetIsReplicatedByDefault(true);  
}  

void UPlayerSyncComponent::BeginPlay()  
{  
    Super::BeginPlay();  
}  

void UPlayerSyncComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)  
{  
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);  

    if (GetOwnerRole() == ROLE_AutonomousProxy)  
    {  
        UpdatePositionAndRotation();  
    }  
}  

void UPlayerSyncComponent::UpdatePositionAndRotation()  
{  
    PlayerPosition = GetOwner()->GetActorLocation();  
    PlayerRotation = GetOwner()->GetActorRotation();  
}  

void UPlayerSyncComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const  
{  
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);  
    DOREPLIFETIME(UPlayerSyncComponent, PlayerPosition);  
    DOREPLIFETIME(UPlayerSyncComponent, PlayerRotation);  
}  
