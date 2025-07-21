#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TradeableItem.generated.h"

UCLASS()
class MYGAME_API ATradeableItem : public AActor
{
    GENERATED_BODY()
    
public:    
    ATradeableItem();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trading")
    FString ItemName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Trading")
    int32 ItemValue;
};
