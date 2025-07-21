#include "AdvancedInventorySystem.h"

AAdvancedInventorySystem::AAdvancedInventorySystem()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AAdvancedInventorySystem::BeginPlay()
{
    Super::BeginPlay();
}

void AAdvancedInventorySystem::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AAdvancedInventorySystem::SortInventory()
{
    Inventory.Sort([](const FInventoryItem& A, const FInventoryItem& B) {
        return A.ItemName < B.ItemName;
    });
}

void AAdvancedInventorySystem::CategorizeItems()
{
    CategorizedInventory.Empty();
    for (const FInventoryItem& Item : Inventory)
    {
        FString Category = "General"; // Determine category based on item properties
        if (!CategorizedInventory.Contains(Category))
        {
            CategorizedInventory.Add(Category, TArray<FInventoryItem>());
        }
        CategorizedInventory[Category].Add(Item);
    }
}
