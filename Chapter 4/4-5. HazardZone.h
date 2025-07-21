#pragma once
#include "CoreMinimal.h" 
#include "GameFramework/Actor.h" 
#include "HazardZone.generated.h"
// Forward declarations 
class UBoxComponent; 
class AMyPlayerCharacter;
UCLASS() class MYGAME_API AHazardZone : public AActor { GENERATED_BODY()
public: AHazardZone();
protected: virtual void BeginPlay() override;
public: virtual void Tick(float DeltaTime) override;
// Damage and activation toggle
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hazard")
float DamagePerSecond;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hazard")
bool bIsActive;

// Collision box for detecting overlaps
UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Hazard")
UBoxComponent* TriggerZone;

// Overlap handlers
UFUNCTION()
void OnPlayerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
                  bool bFromSweep, const FHitResult& SweepResult);

UFUNCTION()
void OnPlayerExit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
 
private: 
// Reference to the overlapping player 
UPROPERTY() AMyPlayerCharacter* PlayerCharacter; };
