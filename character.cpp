//===================================================
//
//授業その7[character.cpp]
//Author:KishimotoEiji
//
//===================================================

//********************************
//インクルード
//********************************
#include "character.h"
#include "main.h"
#include "warrior.h"
#include "wizard.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//********************************
//プロトタイプ宣言
//********************************
namespace
{

}// namespaceはここまで

//===================================================
//生成
//===================================================
CCharacter* CCharacter::Create(JOB job)
{
	CCharacter* pCharacter = nullptr;	//ポインタ

	switch (job)
	{//職業毎の処理
	case JOB::WARRIOR:	/* 戦士 */

		//メモリの動的確保
		pCharacter = new CWarrior;
		break;

	case JOB::WIZARD:	/* 魔法使い */

		//メモリの動的確保
		pCharacter = new CWizard;
		break;

	case JOB::NONE:	/* 選択範囲外 */
	case JOB::MAX:
	default:
		assert(false);
		break;
	}

	if (pCharacter == nullptr)
	{//NULLチェック
		assert(false);
	}

	/* nullptrではない */

	//初期化
	pCharacter->Init();

	//出力
	pCharacter->Output();

	return pCharacter;	//動的確保したものを返す
}

//===================================================
//コンストラクタ
//===================================================
CCharacter::CCharacter()
{
	//メンバ変数のクリア
	m_nHp = 0;
	m_nAttack = 0;
}

//===================================================
//デストラクタ
//===================================================
CCharacter::~CCharacter()
{
	/* 処理無し */
}

//===================================================
//HPの取得
//===================================================
int CCharacter::GetHp()
{
	return m_nHp;
}

//===================================================
//攻撃力の取得
//===================================================
int CCharacter::GetAttack()
{
	return m_nAttack;
}

//===================================================
//HPの設定
//===================================================
void CCharacter::SetHp(const int nHp)
{
	m_nHp = nHp;
}

//===================================================
//攻撃力の設定
//===================================================
void CCharacter::SetAttack(const int nAttack)
{
	m_nAttack = nAttack;
}