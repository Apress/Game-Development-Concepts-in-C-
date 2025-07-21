#include "TradeableItem.h"

ATradeableItem::ATradeableItem()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ATradeableItem::BeginPlay()
{
    Super::BeginPlay();
}

void ATradeableItem::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
