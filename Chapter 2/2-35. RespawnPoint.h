#pragma once

class UBoxComponent;

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RespawnPoint.generated.h"

UCLASS()
class MYGAME_API ARespawnPoint : public AActor
{
    GENERATED_BODY()

public:    
    ARespawnPoint();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(VisibleAnywhere)
    UBoxComponent* RespawnZone;

    UPROPERTY(EditAnywhere, Category = "Respawn")
    bool bIsActive;

    UFUNCTION()
    void RespawnPlayer(class APlayerCharacter* Player);

private:
    FVector GetRandomRespawnLocation();
};
