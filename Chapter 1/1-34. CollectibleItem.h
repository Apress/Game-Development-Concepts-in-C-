Class USphereComponent;

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollectibleItem.generated.h"

UCLASS()
class MYGAME_API ACollectibleItem : public AActor
{
    GENERATED_BODY()

public:
    ACollectibleItem();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(VisibleAnywhere)
    USphereComponent* CollisionSphere;

    UFUNCTION()
    void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
};

UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Effects")
USoundBase* CollectSound;  // To assign sound effects from Blueprint or Editor

UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Effects")
UParticleSystem* CollectEffect;  // To assign particle effects from Blueprint or Editor
