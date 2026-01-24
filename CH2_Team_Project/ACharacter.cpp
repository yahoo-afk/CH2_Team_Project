#include "ACharacter.h"
#include <random>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dis(1, 100);

ACharacter::ACharacter(string NewName, int NewHp, int NewAtk, int NewDef, int NewCritical)
{
	Name = NewName;
	Hp = NewHp;
	Atk = NewAtk;
	Def = NewDef;
	Critical = NewCritical;

	cout << "ACharacter 생성됨: " << Name << " (HP: " << Hp << ")" << endl;
}

ACharacter::~ACharacter()
{
	cout << "ACharacter 소멸됨" << endl;
}

void ACharacter::Attack(ACharacter* Target)
{
	//Atk로 직접 접근해도 좋고, 지역변수에 값을 넣어 호출해도 좋습니다.
	
	if(dis(gen) <= Critical) //1~10사이의 숫자가 나오면 
	{
		cout << Name << "이(가)강력하게 공격합니다" << endl;
		Target->TakeDamage(GetAttack() * 1.5);
	}
	else
	{
		cout << Name << "이(가) 공격합니다" << endl;
		Target->TakeDamage(GetAttack());
	}
}

int ACharacter::GetAttack()
{
	return Atk;
}

void ACharacter::TakeDamage(int DamageAmount)
{	
	DamageAmount -= Def;

	if(DamageAmount  <= 0)
	{
		Hp -= 1;
		cout << Name << "가 " << 1 << "의 피해를 입었습니다." << endl;
		cout << "공격력이 상대의 방어력과 같거나 낮습니다 " << endl;
	}
	else
	{
		Hp -= DamageAmount;
		cout << Name << "가 " << DamageAmount  << "의 피해를 입었습니다." << endl;
		if (isDead())
		{
			Hp = 0;
		}
	}// 
		cout << GetName() << " 남은체력:" << Hp << endl;
}

int ACharacter::GetHp()
{
	return Hp;
}

string ACharacter::GetName()
{
	return Name;
}

//코딩 스타일 수정
bool ACharacter::isDead()
{
	if ( Hp>0)
	{
		return false;
	} //else 제거 가능
	else if(Hp <=0)
	{
		return true;
	}
	
	// return 문 누락
}