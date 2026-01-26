#pragma once
#include <iostream>
#include <string>
#include "Type.h"
using namespace std;

class ACharacter
{
public:
	ACharacter(string NewName, const FUnitStat& NewStat);
	~ACharacter();

protected:
	string Name;
	FUnitStat Stat;

public:
	void Attack(ACharacter* Target);
	void TakeDamage(int DamageAmount);
	bool isDead();
	string GetName()
	{
		return Name;
	}
	int GetHp()
	{
		return Stat.Hp;
	}
	int GetAtk()
	{
		return Stat.Atk;
	}
};