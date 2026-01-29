#pragma once
#include "ACharacter.h"
class APlayer : public ACharacter
{
public:
	APlayer(const string& NewName, const FUnitStat& NewStat);
	
private:
	int Level;
	int Exp;
	int Gold;
	
public:
	void UseItem();
	void LevelUp();
	FAttackResult Attack(ACharacter* Target) override;
};

