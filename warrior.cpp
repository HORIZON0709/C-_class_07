//===================================================
//
//授業その7[warrior.cpp]
//Author:KishimotoEiji
//
//===================================================

//********************************
//インクルード
//********************************
#include "warrior.h"
#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

//********************************
//プロトタイプ宣言
//********************************
namespace
{

}// namespaceはここまで

//===================================================
//コンストラクタ
//===================================================
CWarrior::CWarrior()
{
	//メンバ変数をクリア
	m_nWpnDurability = 0;
}

//===================================================
//デストラクタ
//===================================================
CWarrior::~CWarrior()
{
	/* 処理無し */
}

//===================================================
//初期化
//===================================================
void CWarrior::Init()
{
	//乱数
	srand((unsigned)time(NULL));
	
	//ステータスの設定
	SetHp(rand() % 50 + 50);
	SetAttack(rand() % 5 + 5);

	//メンバ変数を初期化
	m_nWpnDurability = rand() % 4 + 1;
}

//===================================================
//出力
//===================================================
void CWarrior::Output()
{
	printf("\n 戦士 … HP : [%d] /",GetHp());
	printf(" 攻撃力 : [%d] /", GetAttack());
	printf(" 武器耐久力 : [%d]", m_nWpnDurability);
}

//===================================================
//終了
//===================================================
void CWarrior::Uninit()
{
	int nWarrior = 0;	//戦士

	if (m_apCharacter[nWarrior] == nullptr)
	{//NULLチェック
		return;
	}

	/* nullptrではない */

	//メモリの解放
	delete m_apCharacter[nWarrior];
	m_apCharacter[nWarrior] = nullptr;
}

//===================================================
//攻撃する
//===================================================
void CWarrior::Attack(CCharacter* pTarget)
{
	//メッセージ
	printf("\n 戦士の攻撃！相手に[ %d ]のダメージ！", GetAttack());

	pTarget->BeAttacked(GetAttack());	//相手にダメージを与える

	if (m_nWpnDurability > 0)
	{//0未満にはならない
		m_nWpnDurability--;	//武器耐久力が減少
	}

	//メッセージ
	printf("\n 残りの武器耐久力 : [ %d ]", m_nWpnDurability);

	if (m_nWpnDurability <= 0)
	{//武器耐久力が0以下になったとき
		int nAtkHalf = (GetAttack() / 2);	//攻撃力半減
		SetAttack(nAtkHalf);	//攻撃力の設定
	}
}

//===================================================
//攻撃を受ける
//===================================================
void CWarrior::BeAttacked(const int nDamage)
{
	int nHp = GetHp();	//現在のHPを取得

	nHp -= nDamage;	//受けたダメージ分減らす

	SetAttack(nHp);	//残りのHPを設定する

	//表示
	printf("\n 残りHP : [%d]", GetHp());
}