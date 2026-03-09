#pragma once
#include "Skill.h"
class UPlayerAttackSkill:public USkill
{
public:
	UPlayerAttackSkill(ACharacter* Onwer);

	void Play(ACharacter* Target) override;
};

