#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VisualFeedbackComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MYGAME_API UVisualFeedbackComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UVisualFeedbackComponent();

protected:
    virtual void BeginPlay() override;

public:
    UFUNCTION(BlueprintCallable, Category = "Visual Feedback")
    void HighlightObject(bool bIsHighlighted);

    UFUNCTION(BlueprintCallable, Category = "Visual Feedback")
    void ShowActionSuccess();

private:
    UMaterialInstanceDynamic* DynamicMaterial;
};
