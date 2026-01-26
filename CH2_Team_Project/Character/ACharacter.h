#pragma once

#include <iostream>
#include <string>

struct FUnitStat
{
	int Hp;
	int Atk;
	int Def;
	int Critical;
};

using namespace std;

class ACharacter
{
public:
	ACharacter(const string& NewName, const FUnitStat& NewStat);
	virtual ~ACharacter();

protected:
	string Name;
	FUnitStat Stat;
	
public:
	//const 함수는 멤버변수(객체의 상태)가 수정되지 않음을 의미.
	const string& GetName() const { return Name; }
	int GetHp() const { return Stat.Hp; }
	//비교 연산자의 결과는 -> bool
	bool IsDead() const { return Stat.Hp <= 0; }

	void Attack(ACharacter* Target);
	void TakeDamage(int DamageAmount);
};
 