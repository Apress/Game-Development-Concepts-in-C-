#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TradingSystem.generated.h"

UCLASS()
class MYGAME_API ATradingSystem : public AActor
{
    GENERATED_BODY()
    
public:    
    ATradingSystem();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;

    UFUNCTION(BlueprintCallable, Category="Trading")
    void TradeItem(AActor* Buyer, AActor* Seller, ATradeableItem* Item);

private:
    void UpdateInventory(AActor* Actor, ATradeableItem* Item, bool bAddItem);
    void UpdateCurrency(AActor* Actor, int32 Amount);
};
