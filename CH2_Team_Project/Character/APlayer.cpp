#include "APlayer.h"
#include "../UPlayerAttackSkill.h"
#include "../UPlayerRandomAttack.h"
#include "../UPlayerStrikeSkill.h"
using namespace std;

APlayer::APlayer(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
	Level = 1;
	Exp = 0;
	Gold = 0;
	/*Skills.push_back(new UPlayerAttackSkill(this));
	Skills.push_back(new UPlayerRandomAttack(this));
	Skills.push_back(new UPlayerStrikeSkill(this));*/

	Skills.push_back(make_unique<UPlayerAttackSkill>(this));
	Skills.push_back(make_unique<UPlayerRandomAttack>(this));
	Skills.push_back(make_unique<UPlayerStrikeSkill>(this));
}
APlayer::~APlayer()
{
	
}
void APlayer::UseItem()
{
	//추후 구현
}
void APlayer::LevelUp()
{
}
//FAttackResult APlayer::Attack(ACharacter* Target)
//{
//	FAttackResult Result = ACharacter::Attack(Target);
//	string AttackMessage = "이(가)대검으로 공격합니다";
//	if (Result.bCritical)
//	{
//		AttackMessage = "이(가)대검으로 목을 공격합니다";
//	}
//	Result.PrintMessage(AttackMessage);
//	return Result;
//}

//void APlayer::UseSkill(ACharacter* Target)
//{
//	Stat.Mp -= 10;
//	
//
//	int ActualDamage = Target->TakeDamage(Stat.Atk * 2);
//	FAttackResult Result;
//	Result.Attacker = this;
//	Result.Target = Target;
//	Result.bCritical = false;
//	Result.Damage = ActualDamage;
//	Result.PrintMessage("스킬발동: 회심의 일격...!");
//}

void APlayer::PlayTurn(ACharacter* Target)
{
	for(int i=0; i<Skills.size(); ++i)
	{
		cout << i + 1 << "." << Skills[i]->GetName() << endl;
	}

	int Choice = 0;

	while(Choice < 1 || Choice >Skills.size())
	{
		cout << "사용할 스킬을 선택해주세요" << endl;
		cin >> Choice;
		if(Choice < 1 || Choice > Skills.size())
		{
			cout << "올바르지 않은 입력입니다" << endl;
		}
	}

	Skills[Choice - 1]->Play(Target);
}