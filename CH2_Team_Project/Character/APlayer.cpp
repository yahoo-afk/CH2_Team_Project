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
void APlayer::Attack(ACharacter* Target)
{
	cout << Name << "이(가) 대검으로 공격합니다" << endl;
	ACharacter::Attack(Target);
}
