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
