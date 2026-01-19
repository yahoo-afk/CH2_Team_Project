#include "ACharacter.h"

ACharacter::ACharacter(string NewName, int NewHp, int NewAtk)
{
	Name = NewName;
	Hp = NewHp;
	Atk = NewAtk;

	cout << "ACharacter 생성됨: " << Name << " (HP: " << Hp << ")" << endl;
}

ACharacter::~ACharacter()
{
	cout << "ACharacter 소멸됨" << endl;
}

void ACharacter::Attack(ACharacter* Target)
{
	cout << Name << "이(가) 공격합니다" << endl;
	Target->TakeDamage(GetAttack());
}

int ACharacter::GetAttack()
{
	return Atk;
}

void ACharacter::TakeDamage(int DamageAmount)
{
	Hp -= DamageAmount;

	cout << Name << "가 " << DamageAmount << "의 피해를 입었습니다." << endl;
	if(Hp <0)
	{
		Hp = 0;
	}
	cout << GetName()<< " 남은체력:" << Hp << endl;
}

int ACharacter::GetHp()
{
	return Hp;
}

string ACharacter::GetName()
{
	return Name;
}

bool ACharacter::isDead()
{
	if ( Hp>0)
	{
		return false;
	}
	else if(Hp <=0)
	{
		return true;
	}
}