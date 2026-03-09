#include "UMonsterAttackSkill.h"
#include "Character/ACharacter.h"
#include <string>
using namespace std;

UMonsterAttackSkill::UMonsterAttackSkill(ACharacter* NewOnwer) :
	USkill(NewOnwer, 0, "물어뜯기")
{

}

void UMonsterAttackSkill::Play(ACharacter* Target)
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

	string AttackMessage = "이(가)달라붙습니다";
	if (Result.bCritical)
	{
		AttackMessage = "이(가)달라붙어 산성으로 공격합니다";
	}
	Result.PrintMessage(AttackMessage);

}