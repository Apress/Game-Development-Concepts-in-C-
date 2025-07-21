#pragma once

class UStaticMeshComponent;

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Platform.generated.h"

UCLASS()
class MYGAME_API APlatform : public AActor
{
    GENERATED_BODY()
    
public:    
    APlatform();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* PlatformMesh;
};
