#include "AMonster.h"

AMonster::AMonster(string NewName,const FUnitStat& NewStat)
	:ACharacter(NewName,NewStat)
{
	Name = "슬라임";
	Stat.Hp = 100;
	Stat.Atk = 15;
	Stat.Def = 5;
	Stat.Critical = 10;
}

AMonster:: ~AMonster()
{
	cout << Name << ":이(가)퇴장합니다" << endl;
}
