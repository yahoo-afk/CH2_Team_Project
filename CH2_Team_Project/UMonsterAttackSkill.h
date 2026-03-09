#pragma once
#include "Skill.h"
class UMonsterAttackSkill:public USkill
{
public:
	UMonsterAttackSkill(ACharacter* Onwer);
	void Play(ACharacter* Target)override;
};

