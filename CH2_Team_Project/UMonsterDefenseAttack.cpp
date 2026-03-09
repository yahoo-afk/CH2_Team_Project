#include "UMonsterDefenseAttack.h"
#include "Character/ACharacter.h"
UMonsterDefenseAttack::UMonsterDefenseAttack(ACharacter* Owner)
	:USkill(Owner,10,"방패로때리기")
{
	
}

void UMonsterDefenseAttack::Play(ACharacter* Target)
{
	int ActualDamage = Target->TakeDamage(Owner->GetDefense() * 5);
	FAttackResult Result;
	Result.Attacker = Owner;
	Result.Target = Target;
	Result.bCritical = false;
	Result.Damage = ActualDamage;
	Result.PrintMessage("방어력에 5배 데미지");
}