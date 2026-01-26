#include "AMonster.h"

AMonster::AMonster(string NewName,const FUnitStat& NewStat)
	:ACharacter(NewName,NewStat)
{
	Stat.Hp = 100;
	Stat.Atk = 15;
	Stat.Def = 5;
	Stat.Critical = 10;
}