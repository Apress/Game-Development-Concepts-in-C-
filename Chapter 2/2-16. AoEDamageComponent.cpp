#include "AoEDamageComponent.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

UAoEDamageComponent::UAoEDamageComponent()
{
    PrimaryComponentTick.bCanEverTick = true;

    AoERadius = 200.0f;
    DamageAmount = 50.0f;
}

void UAoEDamageComponent::BeginPlay()
{
    Super::BeginPlay();

    // Bind the ApplyAoEDamage function to a trigger event or game action
    // Example: UFUNCTION() TriggeredBySpellCast();
    // Bind function: TriggeredBySpellCast.AddDynamic(this, &UAoEDamageComponent::ApplyAoEDamage);
}

void UAoEDamageComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UAoEDamageComponent::ApplyAoEDamage()
{
    FVector Center = GetOwner()->GetActorLocation();

    // Draw debug sphere for visualization
    DrawDebugSphere(GetWorld(), Center, AoERadius, 12, FColor::Red, false, 2.0f);

    // Using SphereOverlapActors to efficiently find overlapping actors
    TArray<AActor*> OverlappingActors;
    TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
    ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn));  // Check for enemy pawns (players or AI characters)

    UKismetSystemLibrary::SphereOverlapActors(
        GetWorld(), 
        Center, 
        AoERadius, 
        ObjectTypes, 
        ACharacter::StaticClass(), 
        TArray<AActor*>(), 
        OverlappingActors
    );

    for (AActor* Actor : OverlappingActors)
    {
        // Apply damage to the actor within AoE radius
        ACharacter* Character = Cast<ACharacter>(Actor);
        if (Character)
        {
            // Call TakeDamage to handle health reduction (this could be a custom function in the character class)
            FDamageEvent DamageEvent;
            Character->TakeDamage(DamageAmount, DamageEvent, nullptr, nullptr);

            // You can implement your own damage handling or health update here for the character, such as:
            // Character->UpdateHealth(DamageAmount);
        }
    }
}
