#include "UIAnimationWidget.h"

void UUIAnimationWidget::PlayButtonHoverAnimation()
{
    if (ButtonHoverAnimation)
    {
        PlayAnimation(ButtonHoverAnimation);
    }
}

void UUIAnimationWidget::PlayNotificationAnimation()
{
    if (NotificationAnimation)
    {
        PlayAnimation(NotificationAnimation);
    }
}
