// 파일명: Character.h
#pragma once
#include <iostream>
#include <string> // 문자열(이름)을 쓰기 위해 필요합니다.
#include "Type.h"

using namespace std;

//주석 제거 합시다.

// [Mission 1] 클래스 선언
// 언리얼 표준: 클래스 이름은 'A'로 시작합니다.
class ACharacter
{
public:
    ACharacter(string NewName,int NewHp, int NewAtk,int NewDef,int NewCritical);
    ~ACharacter();

protected:
    string Name;
    int Hp;
    int Atk;
    int Def;
    int Critical;
    
public:
    void Attack(ACharacter* Target);
    //오타 수정
    void TakeDamage(int DemageAmount);
    
    //간단한 게터는 헤더에 구현하는 것을 권장합니다.
    int GetHp();
    int GetAttack();
    bool isDead();
    string GetName();
};