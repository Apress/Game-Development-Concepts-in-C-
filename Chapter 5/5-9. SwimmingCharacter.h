#pragma once
 
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SwimmingCharacter.generated.h"
 
UCLASS()
class MYGAME_API ASwimmingCharacter : public ACharacter
{
    GENERATED_BODY()
 
public:
    ASwimmingCharacter();
 
protected:
    virtual void BeginPlay() override;
 
public:
    virtual void Tick(float DeltaTime) override;
 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Swimming")
    float SwimSpeed;
 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Swimming")
    float MaxBreathTime;
 
    UFUNCTION(BlueprintCallable, Category = "Swimming")
    void StartSwimming();
 
    UFUNCTION(BlueprintCallable, Category = "Swimming")
    void StopSwimming();
 
private:
    float BreathRemaining;
    bool bIsSwimming;
 
    // Breath management
   
    void DecreaseBreath();
 
    FTimerHandle BreathTimerHandle;
};
