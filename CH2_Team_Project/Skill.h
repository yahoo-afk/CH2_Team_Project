#pragma once

#include<string>

class ACharacter;
class AMonster;
class APlayer;

class USkill
{

public:
	USkill(ACharacter* NewOwner, int NewMpcost, std::string NewName);
	int GetMpCost() { return MpCost; }
	std::string GetName() { return Name; }
	virtual void Play(ACharacter* Target) = 0;

protected:
	ACharacter* Owner;
	std::string Name;
	int MpCost;
};

