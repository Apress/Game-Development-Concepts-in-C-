#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AdvancedNPCSystem.generated.h"

UENUM(BlueprintType)
enum class ENPCState : uint8
{
    Idle       UMETA(DisplayName = "Idle"),
    Interacting UMETA(DisplayName = "Interacting")
};

UCLASS()
class MYGAME_API AAdvancedNPCSystem : public ACharacter
{
    GENERATED_BODY()

public:
    AAdvancedNPCSystem();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    void Interact();

private:
    UPROPERTY(EditAnywhere, Category = "NPC")
    TArray<FString> Dialogues;

    UPROPERTY(EditAnywhere, Category = "NPC")
    TArray<FString> Quests;

    UPROPERTY(EditAnywhere, Category = "NPC")
    float InteractionRadius;

    UPROPERTY(VisibleAnywhere, Category = "NPC")
    ENPCState CurrentState; // NPC state using Enum

    bool bIsPlayerNearby;

    void CheckProximity();
    void ExecuteInteraction();
    void ChangeState(ENPCState NewState);
    void EndInteraction();
};
