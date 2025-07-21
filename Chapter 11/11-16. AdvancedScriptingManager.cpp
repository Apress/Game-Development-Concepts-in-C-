#include "AdvancedScriptingManager.h"
#include "GameFramework/Actor.h"

AAdvancedScriptingManager::AAdvancedScriptingManager()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AAdvancedScriptingManager::ApplyDamage(float Damage)
{
    if (Damage > 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("Damage Applied: %f"), Damage);
        OnDamageTaken.Broadcast(Damage);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("No damage to apply."));
    }
}
