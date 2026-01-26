#include "APlayer.h"


APlayer::APlayer(string NewName, const FUnitStat& NewStat)
	:ACharacter(NewName, NewStat)
{
	Name = "용사";
	Stat.Hp = 200;
	Stat.Atk = 15;
	Stat.Def = 10;
	Stat.Critical = 10;
}
APlayer::~APlayer()
{
	cout << "용사가 퇴장했습니다" << endl;
}
