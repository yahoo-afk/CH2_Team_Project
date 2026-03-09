#pragma once
#include "Skill.h"
class UPlayerRandomAttack :public USkill
{
public:
	UPlayerRandomAttack(ACharacter* Owner);
	void Play(ACharacter* Target)override;
};

