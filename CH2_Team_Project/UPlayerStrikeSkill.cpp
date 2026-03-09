#include "UPlayerStrikeSkill.h"
#include "Character/ACharacter.h"

UPlayerStrikeSkill::UPlayerStrikeSkill(ACharacter*Onwer)
	:USkill(Onwer,10,"대검으로 강력하게때리기")
{
	
}

void UPlayerStrikeSkill::Play(ACharacter* Target)
{	
	int ActualDamage = Target->TakeDamage(Owner->GetAttack() * 2);
	FAttackResult Result;
	Result.Attacker = Owner;
	Result.Target = Target;
	Result.bCritical = false;
	Result.Damage = ActualDamage;
	Result.PrintMessage("스킬발동: 회심의 일격...!");
}
