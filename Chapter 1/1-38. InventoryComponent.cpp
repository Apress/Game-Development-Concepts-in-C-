#include "InventoryComponent.h"
#include "CollectibleItem.h"

UInventoryComponent::UInventoryComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UInventoryComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UInventoryComponent::AddItem(ACollectibleItem* Item)
{
    if (Item)
    {
        Items.Add(Item);
        Item->Destroy();
        // Implement logic to update inventory UI or apply item effects
    }
}
