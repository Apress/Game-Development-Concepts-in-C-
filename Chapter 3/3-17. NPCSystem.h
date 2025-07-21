#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NPCSystem.generated.h"

// Enum to categorize NPC interactions
UENUM(BlueprintType)
enum class ENPCInteractionType : uint8
{
    Dialogue UMETA(DisplayName = "Dialogue"),  // NPCs that offer dialogues
    Quest UMETA(DisplayName = "Quest"),        // NPCs that give quests
    Trade UMETA(DisplayName = "Trade"),        // NPCs that allow trading
    Combat UMETA(DisplayName = "Combat")       // NPCs that engage in combat
};

UCLASS()
class MYGAME_API ANPCSystem : public ACharacter
{
    GENERATED_BODY()

public:
    // Constructor: Initializes default values
    ANPCSystem();

protected:
    // Called when the game starts or when the NPC is spawned
    virtual void BeginPlay() override;

public:
    // Called every frame to check for player proximity
    virtual void Tick(float DeltaTime) override;

    // Function to handle player interactions with the NPC
    void Interact();

private:
    // Determines the type of interaction this NPC provides
    UPROPERTY(EditAnywhere, Category = "NPC Interaction")
    ENPCInteractionType InteractionType;

    // Stores possible dialogue options for the NPC
    UPROPERTY(EditAnywhere, Category = "NPC Interaction")
    TArray<FString> Dialogues; 

    // Stores available quests that the NPC can assign
    UPROPERTY(EditAnywhere, Category = "NPC Interaction")
    TArray<FString> Quests;

    // Defines the radius in which the player must be to trigger interaction
    UPROPERTY(EditAnywhere, Category = "NPC Interaction")
    float InteractionRadius;

    // Boolean flag to check if the player is nearby
    bool bIsPlayerNearby;

    // Checks if the player is within interaction range
    void CheckProximity();

    // Executes the appropriate interaction based on the NPC type
    void ExecuteInteraction();

    // Ends the interaction and resets states if necessary
    void EndInteraction();
};
