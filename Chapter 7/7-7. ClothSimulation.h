#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ClothSimulation.generated.h"

UCLASS()
class MYGAME_API AClothSimulation : public AActor
{
    GENERATED_BODY()

public:
    AClothSimulation();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cloth")
    float GravityStrength;  // The strength of gravity affecting the cloth

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Cloth")
    TArray<FVector> ClothVertices;  // Array to store the positions of cloth vertices

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Cloth")
    TArray<int32> ClothEdges;  // The edges connecting vertices

    void UpdateCloth(float DeltaTime);
};
