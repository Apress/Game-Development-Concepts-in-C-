#include "InventoryManager.h"

UInventoryManager::UInventoryManager()
{
    // Initialize any necessary inventory setup here
}

void UInventoryManager::AddItemToInventory(FName ItemName)
{
    // Search if the item is already in the inventory
    for (FInventoryItem& Item : Inventory)
    {
        if (Item.ItemName == ItemName)
        {
            // If the item already exists, increase the count
            Item.ItemCount++;
            return;
        }
    }

    // If the item is not found, add a new entry with a count of 1
    FInventoryItem NewItem;
    NewItem.ItemName = ItemName;
    NewItem.ItemCount = 1;
    Inventory.Add(NewItem);
}

void UInventoryManager::RemoveItemFromInventory(FName ItemName)
{
    // Loop through the inventory to find and remove the item
    for (int32 Index = 0; Index < Inventory.Num(); Index++)
    {
        if (Inventory[Index].ItemName == ItemName)
        {
            // Decrease the item count or remove entirely
            if (Inventory[Index].ItemCount > 1)
            {
                Inventory[Index].ItemCount--;
            }
            else
            {
                Inventory.RemoveAt(Index);
            }
            return;
        }
    }
}

void UInventoryManager::ApplyItemEffect(FName ItemName)
{
    // Implement logic to apply the effect of the item (e.g., healing, buff, etc.)
    for (const FInventoryItem& Item : Inventory)
    {
        if (Item.ItemName == ItemName)
        {
            // Apply the effect based on the item, could involve applying buffs, healing, etc.

            // Example:
            UE_LOG(LogTemp, Warning, TEXT("Applied effect of item: %s"), *ItemName.ToString());

            return;
        }
    }
}
