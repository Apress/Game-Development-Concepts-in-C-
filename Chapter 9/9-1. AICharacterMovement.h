#pragma once  

#include "CoreMinimal.h"  
#include "GameFramework/Character.h"  
#include "AICharacterMovement.generated.h"  

UCLASS()  
class MYGAME_API AAICharacterMovement : public ACharacter  
{  
    GENERATED_BODY()  

public:  
    AAICharacterMovement();  

protected:  
    virtual void BeginPlay() override;  

public:  
    virtual void Tick(float DeltaTime) override;  

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Movement")  
    FVector TargetLocation;  

    UFUNCTION(BlueprintCallable, Category = "AI Movement")  
    void MoveToTarget(FVector NewTarget);  

private:  
    void UpdateMovement();  
};  
