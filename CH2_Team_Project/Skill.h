#pragma once

class ACharacter;
class AMonster;
class APlayer;

class USkill
{

public:
	USkill(ACharacter* NewOwner);

protected:
	virtual void Play(ACharacter* Target) = 0;
	ACharacter* Owner;
	
};

