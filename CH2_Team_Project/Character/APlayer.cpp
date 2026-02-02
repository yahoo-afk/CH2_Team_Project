#include "APlayer.h"

using namespace std;

APlayer::APlayer(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
	Level = 1;
	Exp = 0;
	Gold = 0;
}

void APlayer::UseItem()
{
	//추후 구현
}
void APlayer::LevelUp()
{
}
FAttackResult APlayer::Attack(ACharacter* Target)
{
	FAttackResult Result = ACharacter::Attack(Target);
	string AttackMessage = "이(가)대검으로 공격합니다";
	if (Result.bCritical)
	{
		AttackMessage = "이(가)대검으로 목을 공격합니다";
	}
	Result.PrintMessage(AttackMessage);
	return Result;
}
void APlayer::UseSkill(ACharacter* Target)
{
	if (Stat.Mp < 10)
	{
		return;
	}
	Stat.Mp -= 10;
	

	int ActualDamage = Target->TakeDamage(Stat.Atk * 2);
	FAttackResult Result;
	Result.Attacker = this;
	Result.Target = Target;
	Result.bCritical = false;
	Result.Damage = ActualDamage;
	Result.PrintMessage("스킬발동: 회심의 일격...!");
}