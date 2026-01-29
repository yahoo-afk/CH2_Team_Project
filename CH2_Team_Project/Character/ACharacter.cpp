#include "ACharacter.h"
#include <random>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dis(1, 100);

ACharacter::ACharacter(const string& NewName, const FUnitStat& NewStat)
{
	Name = NewName;
	Stat = NewStat;
	cout << "ACharacter 생성됨: " << Name << " (HP: " << Stat.Hp << ")" << endl;
}

ACharacter::~ACharacter()
{
	cout << Name << "이(가) 퇴장합니다." << endl;
}

FAttackResult ACharacter::Attack(ACharacter* Target)
{
	//Atk로 직접 접근해도 좋고, 지역변수에 값을 넣어 호출해도 좋습니다.
	//1~10사이의 숫자가 나오면 
	bool bCritical = dis(gen) <= Stat.Critical;
	int Damage = Stat.Atk;
	if (bCritical)
	{
		Damage = static_cast<int>(Damage * 1.5f);
	}
	int FinalDamage = Target->TakeDamage(Damage);
	FAttackResult Result;
	Result.Damage = FinalDamage;
	Result.bCritical = bCritical;
	return Result;
}

int  ACharacter::TakeDamage(int DamageAmount)
{
	//데미지 처리 부분
	DamageAmount -= Stat.Def;
	bool bMinimumDamage = DamageAmount <= 0;

	//max() -> ex) DamageAmount 0 이하면, 무조건 1이 반환.
	DamageAmount = std::max(1, DamageAmount);

	//HP 처리부분
	Stat.Hp -= DamageAmount;
	Stat.Hp = std::max(0, Stat.Hp);

	return DamageAmount;
}
