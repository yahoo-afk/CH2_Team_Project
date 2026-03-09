#pragma once
#include "Skill.h"
class UMonsterAttackSkill:public USkill
{
public:
	UMonsterAttackSkill(ACharacter* NewOnwer);
	void Play(ACharacter* Target)override;
};

