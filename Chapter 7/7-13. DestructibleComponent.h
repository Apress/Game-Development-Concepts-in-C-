#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DestructibleComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MYGAME_API UDestructibleComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UDestructibleComponent();

protected:
    virtual void BeginPlay() override;

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Destruction")
    float DamageThreshold;

    UFUNCTION(BlueprintCallable, Category = "Destruction")
    void ApplyDamage(float Damage, const FVector& HitLocation);

    UFUNCTION(BlueprintCallable, Category = "Destruction")
    void DestroyObject();

private:
    bool bIsDestroyed;
};

