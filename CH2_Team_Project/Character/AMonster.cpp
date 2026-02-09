#include "AMonster.h"

using namespace std;
AMonster::AMonster(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{

}

FAttackResult AMonster::Attack(ACharacter* Target)
{
	FAttackResult Result = ACharacter::Attack(Target);
	string AttackMessage = "이(가)달라붙습니다";
	if (Result.bCritical)
	{
		AttackMessage = "이(가)달라붙어 산성으로 공격합니다";
	}
	Result.PrintMessage(AttackMessage);
	return Result;
}

void AMonster::Heal(int DamageAmount)
{
	int PrevHp = Stat.Hp;
	Stat.Hp += DamageAmount;
	Stat.Hp = min(Stat.Hp, Stat.MaxHp);

	int ActualHeal = Stat.Hp - PrevHp;

	PrintName();
	cout << ActualHeal << " HP를 회복했습니다...!" << endl;
}

void AMonster::UseSkill(ACharacter* Target)
{
	int PrevHp = Stat.Hp;
	Stat.Mp -= 10;

	int ActualDamage = Target->TakeDamage(Stat.Atk);
	FAttackResult Result;
	Result.Attacker = this;
	Result.Target = Target;
	Result.Damage = ActualDamage;
	Result.bCritical = false;
	Result.PrintMessage("스킬발동: 흡혈 ....!");

	Heal(ActualDamage);
}