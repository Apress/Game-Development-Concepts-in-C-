#pragma once

#include "CoreMinimal.h"
#include "InventorySystem.h"
#include "AdvancedInventorySystem.generated.h"

UCLASS()
class MYGAME_API AAdvancedInventorySystem : public AInventorySystem
{
    GENERATED_BODY()

public:
    AAdvancedInventorySystem();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    void SortInventory();
    void CategorizeItems();

private:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<FString, TArray<FInventoryItem>> CategorizedInventory;
};
