#include "Character/ACharacter.h"
#include "Character/AMonster.h"
#include "Character/APlayer.h"
#include <windows.h>

int main()
{
	ACharacter* Player = new APlayer("용사", { 150, 20, 10,10 });	
	ACharacter* Monster = new AMonster("슬라임", { 100,15,5,10 });

	cout << "===========데스매치 시작============" << endl;
	Sleep(1000);

	while (!Player->IsDead() && !Monster->IsDead())
	{
		Player->Attack(Monster);
		if (Monster->IsDead())
		{
			cout << "몬스터가 쓰러졌습니다" << endl;
			cout << "승리했습니다!! 우리의영웅 용사!!" << endl;
			break;
		}
		Sleep(500);
		Monster->Attack(Player);
		if (Player->IsDead())
		{
			cout << "용사는 쓰러졌다 패배했습니다" << endl;
			break;
		}
	}
	
	Sleep(1000);
	
	delete Player;
	delete Monster;
	return 0;
}