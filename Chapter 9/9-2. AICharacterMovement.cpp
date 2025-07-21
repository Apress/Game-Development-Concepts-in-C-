#include "AICharacterMovement.h"  
#include "NavigationSystem.h"  
#include "AIController.h"  

AAICharacterMovement::AAICharacterMovement()  
{  
    PrimaryActorTick.bCanEverTick = true;  
}  

void AAICharacterMovement::BeginPlay()  
{  
    Super::BeginPlay();  
}  

void AAICharacterMovement::Tick(float DeltaTime)  
{  
    Super::Tick(DeltaTime);  
    UpdateMovement();  
}  

void AAICharacterMovement::MoveToTarget(FVector NewTarget)  
{  
    TargetLocation = NewTarget;  
}  

 void AAICharacterMovement::UpdateMovement() 
{
    if (TargetLocation != FVector::ZeroVector) 
    {
        AAIController* AIController = Cast<AAIController>(GetController());
        if (AIController) 
        {
            FAIMoveRequest MoveRequest;
            MoveRequest.SetGoalLocation(TargetLocation);
            MoveRequest.SetAcceptanceRadius(5.0f);  // You can adjust the acceptance radius
 
            FNavPathSharedPtr NavPath;
            AIController->MoveTo(MoveRequest, &NavPath);
        }
    }
}  
