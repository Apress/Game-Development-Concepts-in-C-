#include "InventorySystem.h"

AInventorySystem::AInventorySystem()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AInventorySystem::BeginPlay()
{
    Super::BeginPlay();
}

void AInventorySystem::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AInventorySystem::AddItem(FString ItemName, int32 Quantity)
{
    FInventoryItem* Item = FindItem(ItemName);
    if (Item)
    {
        Item->Quantity += Quantity;
    }
    else
    {
        FInventoryItem NewItem;
        NewItem.ItemName = ItemName;
        NewItem.Quantity = Quantity;
        Inventory.Add(NewItem);
    }
}

void AInventorySystem::RemoveItem(FString ItemName, int32 Quantity)
{
    FInventoryItem* Item = FindItem(ItemName);
    if (Item && Item->Quantity >= Quantity)
    {
        Item->Quantity -= Quantity;
        if (Item->Quantity == 0)
        {
            Inventory.RemoveSingle(*Item);
        }
    }
}

void AInventorySystem::UseItem(FString ItemName)
{
    FInventoryItem* Item = FindItem(ItemName);
    if (Item && Item->Quantity > 0)
    {
        // Implement item usage logic here
        Item->Quantity--;
        if (Item->Quantity == 0)
        {
            Inventory.RemoveSingle(*Item);
        }
    }
}

FInventoryItem* AInventorySystem::FindItem(FString ItemName)
{
    for (FInventoryItem& Item : Inventory)
    {
        if (Item.ItemName == ItemName)
        {
            return &Item;
        }
    }
    return nullptr;
}
