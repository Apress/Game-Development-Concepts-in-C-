#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DynamicPricing.generated.h"

UCLASS()
class MYGAME_API ADynamicPricing : public AActor
{
    GENERATED_BODY()
    
public:    
    ADynamicPricing();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;

    UFUNCTION(BlueprintCallable, Category="Trading")
    void AdjustPrices();

private:
    TArray<ATradeableItem*> TradeableItems;
    void UpdateItemPrice(ATradeableItem* Item);
};
