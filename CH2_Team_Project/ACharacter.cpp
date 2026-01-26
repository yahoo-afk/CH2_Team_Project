#include "ACharacter.h"
#include <random>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dis(1, 100);

ACharacter::ACharacter(string NewName, const FUnitStat& NewStat)
{
	Name = NewName;
	Stat = NewStat;
	cout << "ACharacter 생성됨: " << Name << " (HP: " << Stat.Hp << ")" << endl;
}

ACharacter::~ACharacter()
{
	cout << "ACharacter 소멸됨" << endl;
}

void ACharacter::Attack(ACharacter* Target)
{
	//Atk로 직접 접근해도 좋고, 지역변수에 값을 넣어 호출해도 좋습니다.

	if (dis(gen) <= Stat.Critical) //1~10사이의 숫자가 나오면 
	{
		cout << Name << "이(가)강력하게 공격합니다" << endl;
		Target->TakeDamage(GetAtk() * 1.5);
	}
	else
	{
		cout << Name << "이(가) 공격합니다" << endl;
		Target->TakeDamage(GetAtk());
	}
}

void ACharacter::TakeDamage(int DamageAmount)
{
	DamageAmount -= Stat.Def;
	if (DamageAmount <= 0)
	{
		Stat.Hp -= 1;
		cout << Name << "가 " << 1 << "의 피해를 입었습니다." << endl;
		cout << "공격력이 상대의 방어력과 같거나 낮습니다 " << endl;
	}
	else
	{
		Stat.Hp -= DamageAmount;
		cout << Name << "가 " << DamageAmount << "의 피해를 입었습니다." << endl;
		if (isDead())
		{
			Stat.Hp = 0;
		}
	}
	cout << GetName() << " 남은체력:" << Stat.Hp << endl;
}

bool ACharacter::isDead()
{
	if (Stat.Hp > 0)
	{
		return false;
	}
	return true;
}


