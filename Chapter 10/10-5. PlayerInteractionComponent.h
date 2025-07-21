#pragma once
 
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerInteractionComponent.generated.h"
 
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MYGAME_API UPlayerInteractionComponent : public UActorComponent
{
    GENERATED_BODY()
 
public:
    UPlayerInteractionComponent();
 
protected:
    virtual void BeginPlay() override;
 
public:
    UFUNCTION(Server, Reliable, WithValidation)
    void Server_Interact(AActor* TargetActor);
 
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_PlayInteractionEffect(AActor* TargetActor);
};
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))  
class MYGAME_API UPlayerInteractionComponent : public UActorComponent  
{  
    GENERATED_BODY()  

public:  
    UPlayerInteractionComponent();  

protected:  
    virtual void BeginPlay() override;  

public:  
    UFUNCTION(Server, Reliable, WithValidation)  
    void Server_Interact(AActor* TargetActor);  

    UFUNCTION(NetMulticast, Reliable)  
    void Multicast_PlayInteractionEffect(AActor* TargetActor);  
};  
