#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

Class UStaticMeshComponent;

#include "DestructibleObject.generated.h"

UCLASS()
class MYGAME_API ADestructibleObject : public AActor
{
    GENERATED_BODY()

public:    
    ADestructibleObject();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* DestructibleMesh;

    UPROPERTY(EditDefaultsOnly, Category = "Destruction")
    float MaxHealth;

    UPROPERTY(BlueprintReadOnly, Category = "Destruction")
    float CurrentHealth;

    UFUNCTION()
    void TakeDamage(float DamageAmount);

private:
    void DestroyObject();
};
