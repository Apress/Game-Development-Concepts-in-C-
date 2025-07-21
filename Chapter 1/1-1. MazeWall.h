#pragma once

class UStaticMeshComponent; 

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MazeWall.generated.h"

UCLASS()
class MYGAME_API AMazeWall : public AActor
{
    GENERATED_BODY()
    
public:    
    AMazeWall();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* MazeWall;
};
