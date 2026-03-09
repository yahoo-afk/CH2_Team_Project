#include "AMonster.h"
#include "../UMonsterAttackSkill.h"
#include "../UMonsterDefenseAttack.h"
#include "../UMonsterDrainSkill.h"

using namespace std;
AMonster::AMonster(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
	Skills.push_back(make_unique<UMonsterAttackSkill>(this));
	Skills.push_back(make_unique<UMonsterDefenseAttack>(this));
	Skills.push_back(make_unique<UMonsterDrainSkill>(this));
}

AMonster::~AMonster()
{
	

}

//FAttackResult AMonster::Attack(ACharacter* Target)
//{
//	FAttackResult Result = ACharacter::Attack(Target);
//	string AttackMessage = "이(가)달라붙습니다";
//	if (Result.bCritical)
//	{
//		AttackMessage = "이(가)달라붙어 산성으로 공격합니다";
//	}
//	Result.PrintMessage(AttackMessage);
//	return Result;
//}

//void AMonster::UseSkill(ACharacter* Target)
//{
//	int PrevHp = Stat.Hp;
//	Stat.Mp -= 10;
//
//	int ActualDamage = Target->TakeDamage(Stat.Atk);
//	FAttackResult Result;
//	Result.Attacker = this;
//	Result.Target = Target;
//	Result.Damage = ActualDamage;
//	Result.bCritical = false;
//	Result.PrintMessage("스킬발동: 흡혈 ....!");
//
//	Heal(ActualDamage);
//}

void AMonster::PlayTurn(ACharacter*Target)
{
	int index = GetRandomInt(Skills.size());
	Skills[index]->Play(Target);
}