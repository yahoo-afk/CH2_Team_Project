#pragma once
#include "Skill.h"
class UMonsterDrainSkill:public USkill
{
public:
	UMonsterDrainSkill(ACharacter* Onwer);
	void Play(ACharacter* Target) override;
};

