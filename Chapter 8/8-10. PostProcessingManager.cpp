#include "PostProcessingManager.h"
#include "Components/PostProcessComponent.h"

APostProcessingManager::APostProcessingManager()
{
    PrimaryActorTick.bCanEverTick = true;
    PostProcessComponent = CreateDefaultSubobject<UPostProcessComponent>(TEXT("PostProcessComponent"));
    RootComponent = PostProcessComponent;

    BloomIntensity = 1.0f;
    ColorGrading = FVector4(1.0f, 1.0f, 1.0f, 1.0f);
}

void APostProcessingManager::BeginPlay()
{
    Super::BeginPlay();
    UpdatePostProcessing(BloomIntensity, ColorGrading);
}

void APostProcessingManager::UpdatePostProcessing(float NewBloomIntensity, FVector4 NewColorGrading)
{
    if (PostProcessComponent)
    {
        PostProcessComponent->Settings.bOverride_BloomIntensity = true;
        PostProcessComponent->Settings.BloomIntensity = NewBloomIntensity;

        PostProcessComponent->Settings.bOverride_ColorSaturation = true;
        PostProcessComponent->Settings.ColorSaturation = FVector(NewColorGrading.X, NewColorGrading.Y, NewColorGrading.Z);
    }
}
