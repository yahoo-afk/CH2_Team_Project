#pragma once

#include "ACharacter.h"

class AMonster : public ACharacter
{
public:
	void PlayTurn(ACharacter* Target)override;
	AMonster(const std::string& NewName, const FUnitStat& NewStat);
	~AMonster()override;
	//FAttackResult Attack(ACharacter*Target)override;
	// void UseSkill(ACharacter* Target)override;
};