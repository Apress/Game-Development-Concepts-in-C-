#include "MyWheeledVehiclePawn.h"
#include "WheeledVehicleMovementComponent.h"
 
AMyWheeledVehiclePawn::AMyWheeledVehiclePawn()
{
    // Optional initialization
}
 
void AMyWheeledVehiclePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
 
    PlayerInputComponent->BindAxis("MoveForward", this, &AMyWheeledVehiclePawn::MoveForward);
    PlayerInputComponent->BindAxis("TurnRight", this, &AMyWheeledVehiclePawn::TurnRight);
}
 
void AMyWheeledVehiclePawn::MoveForward(float Value)
{
    GetVehicleMovementComponent()->SetThrottleInput(Value);
}
 
void AMyWheeledVehiclePawn::TurnRight(float Value)
{
    GetVehicleMovementComponent()->SetSteeringInput(Value);
}
