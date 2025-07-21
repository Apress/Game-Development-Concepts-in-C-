#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SkillTreeManager.generated.h"

UCLASS()
class MYGAME_API ASkillTreeManager : public AActor
{
    GENERATED_BODY()

public:
    ASkillTreeManager();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SkillTree")
    TArray<class USkill*> AvailableSkills;

    UPROPERTY(BlueprintReadOnly, Category="SkillTree")
    TArray<class USkill*> UnlockedSkills;

    UFUNCTION(BlueprintCallable, Category="SkillTree")
    void UnlockSkill(class USkill* Skill);

    UFUNCTION(BlueprintCallable, Category="SkillTree")
    void UseSkill(class USkill* Skill);
};
