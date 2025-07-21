#include "ModdingManager.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"

AModdingManager::AModdingManager()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AModdingManager::LoadModFromPath(FString ModPath)
{
    // Example: Load a plugin or script from the file system
    if (FPaths::FileExists(ModPath))
    {
        UE_LOG(LogTemp, Warning, TEXT("Mod Loaded from Path: %s"), *ModPath);
        // Custom logic for integrating mod data
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Mod path not found: %s"), *ModPath);
    }
}

UObject* AModdingManager::LoadAsset(FString AssetPath)
{
    FStreamableManager& StreamableManager = UAssetManager::GetStreamableManager();
    TSoftObjectPtr<UObject> AssetReference(AssetPath);

    UObject* LoadedAsset = StreamableManager.LoadSynchronous(AssetReference, false);
    if (LoadedAsset)
    {
        UE_LOG(LogTemp, Warning, TEXT("Asset Loaded: %s"), *AssetPath);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to Load Asset: %s"), *AssetPath);
    }

    return LoadedAsset;
}
