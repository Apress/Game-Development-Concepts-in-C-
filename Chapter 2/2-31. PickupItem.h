#pragma once

class USaticMeshComponent;
class USphereComponent;

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupItem.generated.h"

UCLASS()
class MYGAME_API APickupItem : public AActor
{
    GENERATED_BODY()

public:    
    APickupItem();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* PickupMesh;

    UPROPERTY(VisibleAnywhere)
    USphereComponent* CollisionSphere;

    UPROPERTY(EditDefaultsOnly, Category = "Pickup")
    FName ItemName;

    UPROPERTY(EditDefaultsOnly, Category = "Pickup")
    float PickupRadius;

    UFUNCTION()
    void OnPlayerPickup(class APlayerCharacter* Player);

private:
    bool bIsPickupable;
};
