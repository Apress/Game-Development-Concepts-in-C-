#include "GameHUD.h"
#include "Engine/Canvas.h"

void AGameHUD::DrawHUD()
{
    Super::DrawHUD();

    // Example: Draw health bar and score
    DrawHealthBar(0.75f); // 75% health
    DrawScore(1500); // Player score
}

void AGameHUD::DrawHealthBar(float HealthPercentage)
{
    FVector2D HealthBarEnd = HealthBarPosition + HealthBarSize * HealthPercentage;
    DrawRect(HealthBarColor, HealthBarPosition.X, HealthBarPosition.Y, HealthBarEnd.X - HealthBarPosition.X, HealthBarSize.Y);
}

void AGameHUD::DrawScore(int32 PlayerScore)
{
    FString ScoreText = FString::Printf(TEXT("Score: %d"), PlayerScore);
    DrawText(ScoreText, FLinearColor::White, ScorePosition.X, ScorePosition.Y);
}
