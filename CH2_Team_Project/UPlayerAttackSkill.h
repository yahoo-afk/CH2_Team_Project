#pragma once
#include "Skill.h"
class UPlayerAttackSkill:public USkill
{
public:
	UPlayerAttackSkill(ACharacter* NewOnwer);

	void Play(ACharacter* Target) override;
};

