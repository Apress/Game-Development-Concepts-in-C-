#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DynamicLighting.generated.h"

UCLASS()
class MYGAME_API UDynamicLighting : public UObject
{
    GENERATED_BODY()

public:
    UDynamicLighting();

    void UpdateLighting(float TimeOfDay);
};
