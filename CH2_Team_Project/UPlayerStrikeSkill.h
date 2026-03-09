#pragma once
#include"Skill.h"
class UPlayerStrikeSkill :public USkill
{
public:
	UPlayerStrikeSkill(ACharacter* Onwer);
	void Play(ACharacter* Target)override;
};

