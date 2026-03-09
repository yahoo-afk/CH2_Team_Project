#include "UPlayerRandomAttack.h"
#include "Character/ACharacter.h"
UPlayerRandomAttack::UPlayerRandomAttack(ACharacter* Owner)
	:USkill(Owner,15,"운으로때리기")
{
}

void UPlayerRandomAttack::Play(ACharacter* Target)
{
	int ActualDamage = Target->TakeDamage(Owner->GetRandomInt() * 1);
	
	FAttackResult Result;
	Result.Attacker = Owner;
	Result.Target = Target;
	Result.bCritical = false;
	Result.Damage = ActualDamage;
	Result.PrintMessage("운에 따른공격");
}