#pragma once

#include "CoreMinimal.h"

class AActor;

#include "ChainReactionComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYGAME_API UChainReactionComponent : public UActorComponent
{
    GENERATED_BODY()

public:    
    UChainReactionComponent();

protected:
    virtual void BeginPlay() override;


    UFUNCTION()
    void TriggerChainReaction();
};
