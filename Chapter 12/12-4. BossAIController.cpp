#include "BossAIController.h"  
#include "GameFramework/Actor.h"  
#include "Kismet/GameplayStatics.h"  

ABossAIController::ABossAIController()  
{  
    bIsInAttackRange = false;  
}  

void ABossAIController::Tick(float DeltaTime)  
{  
    Super::Tick(DeltaTime);  

    // Example AI logic to chase the player  
    AActor* PlayerActor = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);  
    if (PlayerActor)  
    {  
        MoveToActor(PlayerActor);  
    }  

    // Check if in attack range  
    if (bIsInAttackRange)  
    {  
        PerformAttack();  
    }  
}  

void ABossAIController::PerformAttack()  
{  
    // Logic for performing an attack  
    UE_LOG(LogTemp, Warning, TEXT("Boss is Attacking!"));  
    // Custom attack logic, such as spawning a projectile or triggering an animation  
}
