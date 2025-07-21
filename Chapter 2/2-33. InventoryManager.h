#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InventoryManager.generated.h"

// Define a structure to hold item information, including the item type and its count in inventory

USTRUCT(BlueprintType)

struct FInventoryItem
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    FName ItemName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    int32 ItemCount;

    FInventoryItem() : ItemName(NAME_None), ItemCount(0) {}
};

UCLASS()
class MYGAME_API UInventoryManager : public UObject
{
    GENERATED_BODY()

public:
    UInventoryManager();

    // Add an item to the inventory
    UFUNCTION(BlueprintCallable)
    void AddItemToInventory(FName ItemName);

    // Remove an item from the inventory
    UFUNCTION(BlueprintCallable)
    void RemoveItemFromInventory(FName ItemName);

    // Apply the effect of an item
    UFUNCTION(BlueprintCallable)
    void ApplyItemEffect(FName ItemName);

protected:
    // Inventory array to store the items and their counts
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
    TArray<FInventoryItem> Inventory;

};
