#pragma once

class ACollectibleItem;

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MYGAME_API UInventoryComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UInventoryComponent();

protected:
    virtual void BeginPlay() override;

public:
    void AddItem(ACollectibleItem* Item);

private:
    UPROPERTY(VisibleAnywhere)
    TArray<ACollectibleItem*> Items;
};
