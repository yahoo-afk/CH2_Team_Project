#pragma once
#include "ACharacter.h"
class AMonster : public ACharacter
{
public:
	AMonster(string NewName, const FUnitStat& NewStat);
	~AMonster()override;
};
