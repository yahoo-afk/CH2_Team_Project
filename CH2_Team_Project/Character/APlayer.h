#pragma once
#include "ACharacter.h"
class APlayer : public ACharacter
{
public:
	APlayer(const std::string& NewName, const FUnitStat& NewStat);
	~APlayer()override;
private:
	int Level;
	int Exp;
	int Gold;
	
public:
	void PlayTurn(ACharacter*Player)override;
	void UseItem();
	void LevelUp();
	//FAttackResult Attack(ACharacter* Target) override;
	//void UseSkill(ACharacter* Target)override;
};

