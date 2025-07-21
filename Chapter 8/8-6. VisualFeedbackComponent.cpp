#include "VisualFeedbackComponent.h"
#include "GameFramework/Actor.h"
#include "Components/PrimitiveComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

UVisualFeedbackComponent::UVisualFeedbackComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UVisualFeedbackComponent::BeginPlay()
{
    Super::BeginPlay();

    UPrimitiveComponent* PrimitiveComponent = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    if (PrimitiveComponent)
    {
        DynamicMaterial = PrimitiveComponent->CreateAndSetMaterialInstanceDynamic(0);
    }
}

void UVisualFeedbackComponent::HighlightObject(bool bIsHighlighted)
{
    if (DynamicMaterial)
    {
        DynamicMaterial->SetScalarParameterValue("HighlightIntensity", bIsHighlighted ? 1.0f : 0.0f);
    }
}

void UVisualFeedbackComponent::ShowActionSuccess()
{
    if (DynamicMaterial)
    {
        DynamicMaterial->SetVectorParameterValue("GlowColor", FLinearColor::Green); 
    }
}
