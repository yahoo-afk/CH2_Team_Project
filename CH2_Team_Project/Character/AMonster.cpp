#include "AMonster.h"

AMonster::AMonster(const string& NewName,const FUnitStat& NewStat)
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
	cout << Name << AttackMessage << endl;
	cout << Name << "이(가)" << Result.Damage << "만큼 데미지를 주었습니다" << endl;
	cout << Target->GetName() << "의 남은 체력" << Target->GetHp() << "입니다" << endl;
	return Result;
}