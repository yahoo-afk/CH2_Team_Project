#include "Skill.h"
#include "Character/ACharacter.h"
#include "Character/AMonster.h"
#include "Character/APlayer.h"

using namespace std;

USkill::USkill(ACharacter* NewOwner, int NewMpcost, string NewName)
{
	 Owner = NewOwner;
	 MpCost = NewMpcost;
	 Name = NewName;
}

