#include "UMonsterDrainSkill.h"
#include "Character/ACharacter.h"
UMonsterDrainSkill::UMonsterDrainSkill(ACharacter* Owner)
	:USkill(Owner,15,"ÈíÇ÷°ø°Ý")
{

}

void UMonsterDrainSkill::Play(ACharacter* Target)
{
	int PrevHp = Owner->GetHp();
	
	int ActualDamage = Target->TakeDamage(Owner->GetAttack());
	FAttackResult Result;
	Result.Attacker = Owner;
	Result.Target = Target;
	Result.Damage = ActualDamage;
	Result.bCritical = false;
	Result.PrintMessage("½ºÅ³¹ßµ¿: ÈíÇ÷ ....!");
	
	Owner->Heal(ActualDamage);
}