#include "SaveGameManager.h"
#include "Kismet/GameplayStatics.h"

void SaveGameState()
{
    USaveGameManager* SaveGameInstance = Cast<USaveGameManager>(UGameplayStatics::CreateSaveGameObject(USaveGameManager::StaticClass()));

    SaveGameInstance->PlayerScore = 100; // Example value
    SaveGameInstance->PlayerLocation = FVector(200.0f, 300.0f, 400.0f); // Example location
    SaveGameInstance->PlayerRotation = FRotator(0.0f, 45.0f, 0.0f); // Example rotation

    UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("PlayerSaveSlot"), 0);
}

void LoadGameState()
{
    USaveGameManager* LoadedGameInstance = Cast<USaveGameManager>(UGameplayStatics::LoadGameFromSlot(TEXT("PlayerSaveSlot"), 0));

    if (LoadedGameInstance)
    {
        int32 PlayerScore = LoadedGameInstance->PlayerScore;
        FVector PlayerLocation = LoadedGameInstance->PlayerLocation;
        FRotator PlayerRotation = LoadedGameInstance->PlayerRotation;

        // Apply the loaded values (example)
        UE_LOG(LogTemp, Warning, TEXT("Score: %d, Location: %s, Rotation: %s"),
            PlayerScore,
            *PlayerLocation.ToString(),
            *PlayerRotation.ToString());
    }
}
