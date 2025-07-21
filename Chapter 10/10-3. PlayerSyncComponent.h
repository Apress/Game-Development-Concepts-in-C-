#pragma once  

#include "CoreMinimal.h"  
#include "Components/ActorComponent.h"  
#include "PlayerSyncComponent.generated.h"  

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))  
class MYGAME_API UPlayerSyncComponent : public UActorComponent  
{  
    GENERATED_BODY()  

public:  
    UPlayerSyncComponent();  

protected:  
    virtual void BeginPlay() override;  

public:  
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;  

    UPROPERTY(Replicated, BlueprintReadWrite, Category = "Synchronization")  
    FVector PlayerPosition;  

    UPROPERTY(Replicated, BlueprintReadWrite, Category = "Synchronization")  
    FRotator PlayerRotation;  

    void UpdatePositionAndRotation();  
};  
