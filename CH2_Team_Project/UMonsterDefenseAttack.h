#pragma once
#include "Skill.h"
class UMonsterDefenseAttack :public USkill
{
public:
	UMonsterDefenseAttack(ACharacter* Owner);
	void Play(ACharacter* Target)override;
};

