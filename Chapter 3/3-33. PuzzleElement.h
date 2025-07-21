#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

class UStaticMeshComponent;

#include "PuzzleElement.generated.h"

UCLASS()
class MYGAME_API APuzzleElement : public AActor
{
    GENERATED_BODY()
    
public:    
    APuzzleElement();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;

    UFUNCTION()
    void OnInteract();

private:
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* PuzzleMesh;
};
