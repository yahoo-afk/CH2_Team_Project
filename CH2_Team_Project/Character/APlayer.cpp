#include "APlayer.h"


APlayer::APlayer(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
	Name = "용사";
	Stat.Hp = 200;
	Stat.Atk = 15;
	Stat.Def = 10;
	Stat.Critical = 10;
	
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
	if(Result.bCritical)
	{
		AttackMessage = "이(가)대검으로 목을 공격합니다";
	}
	cout << Name << AttackMessage << endl;
	cout << Name << "이(가)" << Result.Damage << "만큼 데미지를 주었습니다" << endl;
	cout << Target->GetName() << "의 남은 체력" << Target->GetHp() << "입니다" << endl;
	return Result;
}
