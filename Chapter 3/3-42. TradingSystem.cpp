#include "TradingSystem.h"
#include "TradeableItem.h"

ATradingSystem::ATradingSystem()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ATradingSystem::BeginPlay()
{
    Super::BeginPlay();
}

void ATradingSystem::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ATradingSystem::TradeItem(AActor* Buyer, AActor* Seller, ATradeableItem* Item)
{
    if (Buyer && Seller && Item)
    {
        // Implement trading logic here
        int32 ItemValue = Item->ItemValue;

        // Update Seller's inventory and currency
        UpdateInventory(Seller, Item, false);
        UpdateCurrency(Seller, ItemValue);

        // Update Buyer's inventory and currency
        UpdateInventory(Buyer, Item, true);
        UpdateCurrency(Buyer, -ItemValue);

        // Provide feedback on trade completion
    }
}

void ATradingSystem::UpdateInventory(AActor* Actor, ATradeableItem* Item, bool bAddItem)
{
    // Implement inventory update logic here
}

void ATradingSystem::UpdateCurrency(AActor* Actor, int32 Amount)
{
    // Implement currency update logic here
}
