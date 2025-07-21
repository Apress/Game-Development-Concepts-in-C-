#include "SkillTreeManager.h"
#include "Skill.h"

ASkillTreeManager::ASkillTreeManager()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ASkillTreeManager::BeginPlay()
{
    Super::BeginPlay();
}

void ASkillTreeManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ASkillTreeManager::UnlockSkill(USkill* Skill)
{
    if (Skill && !UnlockedSkills.Contains(Skill))
    {
        UnlockedSkills.Add(Skill);
        // Trigger any additional actions, like UI updates
    }
}

void ASkillTreeManager::UseSkill(USkill* Skill)
{
    if (UnlockedSkills.Contains(Skill))
    {
        // Apply the skill's effect (e.g., cast a spell or boost stats)
    }
}
