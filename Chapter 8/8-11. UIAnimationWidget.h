#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UIAnimationWidget.generated.h"

UCLASS()
class MYGAME_API UUIAnimationWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "UI Animations")
    void PlayButtonHoverAnimation();

    UFUNCTION(BlueprintCallable, Category = "UI Animations")
    void PlayNotificationAnimation();

protected:
    UPROPERTY(meta = (BindWidgetAnim), Transient)
    UWidgetAnimation* ButtonHoverAnimation;

    UPROPERTY(meta = (BindWidgetAnim), Transient)
    UWidgetAnimation* NotificationAnimation;
};

