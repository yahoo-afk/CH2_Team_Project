#include "AMonster.h"

AMonster::AMonster(const string& NewName,const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
	
}

void AMonster::Attack(ACharacter* Target)
{
	cout << Name<<"의물어뜯기" << endl;
	ACharacter::Attack(Target);
}