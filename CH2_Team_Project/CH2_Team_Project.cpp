#include "Character/ACharacter.h"
#include "Character/AMonster.h"
#include "Character/APlayer.h"
#include "ABattleManager.h"
#include <windows.h>

using namespace std;


void WaitForPlayerInput()
{
	system("pause");
	cout << endl;
}

bool BattleTrun(ACharacter* Attacker, ACharacter* Defender)
{
	Attacker->ShowStat();
	Defender->ShowStat();
	
	Attacker->PlayTurn(Defender);
	WaitForPlayerInput();
	
	if (Defender->IsDead()) 
	{
		cout << Attacker->GetName()<< "이(가)승리했습니다" << endl;
		cout << Defender->GetName() << "이(가) 사망했습니다" << endl;
		return true;
	}

}


int main()
{
	auto BattleManager = make_unique<ABattleManager>();


	FUnitStat PlayerStat(150, 50, 10, 5, 10);
	FUnitStat MonsterStat(100, 30, 10, 5, 10);

		
	unique_ptr<ACharacter>Player = make_unique<APlayer>("용사", PlayerStat);
	unique_ptr<ACharacter>Monster = make_unique<AMonster>("슬라임", MonsterStat);
	

	cout << "===  데스매치 시작!  ===" << endl;

	BattleManager->WaitForPlayerInput();
	BattleManager->RunBattle(Player.get(), Monster.get());
	BattleManager->WaitForPlayerInput();

	cout << "===  데스매치 종료!  ===" << endl;


	return 0;
}