#include "UPlayerAttackSkill.h"
#include "Character/ACharacter.h"
#include <string>
using namespace std;

UPlayerAttackSkill::UPlayerAttackSkill(ACharacter* NewOnwer)
	:USkill(NewOnwer,0,"대검으로때리기")
{

}

void UPlayerAttackSkill::Play(ACharacter* Target)
{
	bool bCritical = Owner->GetRandomInt() <= Owner->GetCritical();
	int Damage = Owner->GetAttack();
	if (bCritical)
	{
		Damage = static_cast<int>(Damage * 1.5f);
	}

	FAttackResult Result;
	Result.Attacker = Owner;
	Result.Target = Target;
	int FinalDamage = Target->TakeDamage(Damage);
	Result.Damage = FinalDamage;
	Result.bCritical = bCritical;
	
	string AttackMessage = "이(가)대검으로 공격합니다";
	if (Result.bCritical)
	{
		AttackMessage = "이(가)대검으로 목을 공격합니다";
	}
	Result.PrintMessage(AttackMessage);

}