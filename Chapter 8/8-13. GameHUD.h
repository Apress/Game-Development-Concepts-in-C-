#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameHUD.generated.h"

UCLASS()
class MYGAME_API AGameHUD : public AHUD
{
    GENERATED_BODY()

public:
    virtual void DrawHUD() override;

protected:
    void DrawHealthBar(float HealthPercentage);
    void DrawScore(int32 PlayerScore);

private:
    UPROPERTY(EditAnywhere, Category = "HUD Settings")
    FVector2D HealthBarPosition;

    UPROPERTY(EditAnywhere, Category = "HUD Settings")
    FVector2D ScorePosition;

    UPROPERTY(EditAnywhere, Category = "HUD Settings")
    FVector2D HealthBarSize;

    UPROPERTY(EditAnywhere, Category = "HUD Settings")
    FLinearColor HealthBarColor;
};
