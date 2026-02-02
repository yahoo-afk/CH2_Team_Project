#pragma once

#include "ACharacter.h"

class AMonster : public ACharacter
{
public:
	AMonster(const string& NewName, const FUnitStat& NewStat);
	FAttackResult Attack(ACharacter*Target)override;
	 void UseSkill(ACharacter* Target)override;
	 void Heal(int DamageAmount);
};