#pragma once

#include "ACharacter.h"

class AMonster : public ACharacter
{
public:
	AMonster(const string& NewName, const FUnitStat& NewStat);
};
