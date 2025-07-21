#pragma once

class UStaticMeshComponent;

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractiveObject.generated.h"

UCLASS()
class MYGAME_API AInteractiveObject : public AActor
{
    GENERATED_BODY()

public:
    AInteractiveObject();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(VisibleAnywhere, EditDefaultsOnly, Category = "Interactive Object")
    UStaticMeshComponent* ObjectMesh;

    bool bIsActive;

    UFUNCTION()
    void Interact();
};
