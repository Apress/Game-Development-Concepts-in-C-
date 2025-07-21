 #pragma once
 
#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "MyWheeledVehiclePawn.generated.h"
 
UCLASS()
class MYGAME_API AMyWheeledVehiclePawn : public AWheeledVehiclePawn
{
    GENERATED_BODY()
 
public:
    AMyWheeledVehiclePawn();
 
protected:
    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
 
    void MoveForward(float Value);
    void TurnRight(float Value);
};
