#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InventorySystem.generated.h"

USTRUCT(BlueprintType)
struct FInventoryItem
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ItemName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Quantity;

    FInventoryItem()
    {
        ItemName = "";
        Quantity = 1;
    }
};

UCLASS()
class MYGAME_API AInventorySystem : public AActor
{
    GENERATED_BODY()

public:
    AInventorySystem();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    void AddItem(FString ItemName, int32 Quantity);
    void RemoveItem(FString ItemName, int32 Quantity);
    void UseItem(FString ItemName);

private:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FInventoryItem> Inventory;

    FInventoryItem* FindItem(FString ItemName);
};
