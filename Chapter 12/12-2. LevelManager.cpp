#include "LevelManager.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
 
ALevelManager::ALevelManager()
{
    PrimaryActorTick.bCanEverTick = true;
}
 
void ALevelManager::LoadLevelAssets()
{
    UE_LOG(LogTemp, Warning, TEXT("Attempting to load assets asynchronously"));
 
    // Example: Asynchronously load a Static Mesh asset
    FStringAssetReference AssetRef(TEXT("/Game/Environment/Meshes/Tree.Tree")); // Change to your asset path
 
    FStreamableManager& Streamable = UAssetManager::GetStreamableManager();
 
    Streamable.RequestAsyncLoad(
        AssetRef,
        FStreamableDelegate::CreateUObject(this, &ALevelManager::OnAssetLoaded)
    );
}
 
void ALevelManager::OnAssetLoaded()
{
    UE_LOG(LogTemp, Warning, TEXT("Asset loaded successfully."));
    // You can now use the asset (e.g., spawn it into the level)
}
 
void ALevelManager::SetGameplayTriggers()
{
    UE_LOG(LogTemp, Warning, TEXT("Gameplay Triggers Set"));
    // Logic for placing triggers and interactive elements
}
