#pragma once

#include <iostream>
#include <string>

using namespace std;

class ACharacter;

struct FUnitStat
{
	int MaxHp;
	int MaxMp;
	int Atk;
	int Def;
	int Critical;

	int Hp = 0;
	int Mp = 0;

	FUnitStat()
	{

	}

	FUnitStat(int MaxHp, int MaxMp, int Atk, int Def, int Critical)
	{
		this->MaxHp = MaxHp;
		this->MaxMp = MaxMp;
		this->Atk = Atk;
		this->Def = Def;
		this->Critical = Critical;
	}
};

struct FAttackResult
{
public:
	int Damage;
	bool bCritical;
	ACharacter* Attacker;
	ACharacter* Target; 
	void PrintMessage(const string& AttackMessage);
};


class ACharacter
{
public:
	ACharacter(const string& NewName, const FUnitStat& NewStat);
	virtual ~ACharacter();
	FUnitStat Stat;

protected:
	string Name;

public:
	//const 함수는 멤버변수(객체의 상태)가 수정되지 않음을 의미.
	const string& GetName() const { return Name; }
	int GetHp() const { return Stat.Hp; }
	//비교 연산자의 결과는 -> bool
	bool IsDead() const { return Stat.Hp <= 0; }

	virtual FAttackResult Attack(ACharacter* Target);
	int TakeDamage(int DamageAmount);

	virtual void UseSkill(ACharacter* Target) = 0;
	void PrintName();
};
