#pragma once
#include "ACharacter.h"
class APlayer:public ACharacter
{
public:
	APlayer(string NewName, const FUnitStat& NewStat);
	~APlayer()override;
};

