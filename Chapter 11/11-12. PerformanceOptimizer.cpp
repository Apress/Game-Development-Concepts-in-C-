#include "PerformanceOptimizer.h"
#include "Engine/Engine.h"
#include "Engine/Texture.h"

APerformanceOptimizer::APerformanceOptimizer()
{
    PrimaryActorTick.bCanEverTick = false;
}

void APerformanceOptimizer::BeginPlay()
{
    Super::BeginPlay();
    EnableFramerateSmoothing();
    OptimizeTextureSettings();
}

void APerformanceOptimizer::EnableFramerateSmoothing()
{
    if (GEngine)
    {
        GEngine->SetMaxFPS(60);
        UE_LOG(LogTemp, Warning, TEXT("Framerate Smoothing Enabled: Max FPS set to 60."));
    }
}

void APerformanceOptimizer::OptimizeTextureSettings()
{
    for (TObjectIterator<UTexture> It; It; ++It)
    {
        UTexture* Texture = *It;
        if (Texture)
        {
            Texture->MipGenSettings = TMGS_NoMipmaps;
            Texture->CompressionSettings = TC_Default;
            Texture->UpdateResource();
            UE_LOG(LogTemp, Warning, TEXT("Texture Optimized: %s"), *Texture->GetName());
        }
    }
}
