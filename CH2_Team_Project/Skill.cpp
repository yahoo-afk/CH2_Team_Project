#include "Skill.h"
#include "Character/ACharacter.h"
#include "Character/AMonster.h"
#include "Character/APlayer.h"
USkill::USkill(ACharacter* NewOwner)
{
	 Owner = NewOwner;
}

